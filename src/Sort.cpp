// Standard template library include files.
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

//My includes
#include "ParticleHit.h"	//ParticleHit Class 
#include "CloverArray.h"	//CloverArray Class
#include "LeafArray.h"		//Leaf Class
#include "ProcessSilicon.h"	//Silicon Processor
#include "ProcessClovers.h"	//Clover Processor
#include "Declarations.h"	//
#include "Utility.h"		//Utility functions
#include "Sort.h"			//Root header includes, Global Variable declares

//////////////////////////////////////
//			Define geometry			//
//////////////////////////////////////

//const float TargetDistance = 28.5; //target distance in mm Carbon 
const float TargetDistance = 30.00; //target distance in mm 32S 
const float Xoffset = -0.9;//(1172/3 param)
const float Yoffset = -0.7;//(1172/3 param)
//////////////////////////////////////
//		Define Kinematic Values		//
//////////////////////////////////////

//Reaction : X(a,b)Y

//const float BeamEnergy = 33.200; //MeV (Ta) after the retune
//const float BeamEnergy = 33.160; //MeV (Ta) after the retune (1172/3 param)
//const float BeamEnergy = 33.018; //MeV (Ta)  (run1085)
//const float BeamEnergy = 33.048; //MeV (Ta) after the retune
const float BeamEnergy = 33.010; 
//const float BeamEnergy = 34.0;
//const float BeamEnergy = 32.8; //MeV (Ta) early Mylar runs

//	(p,d)
const float Ma = 1.00782; //Beam mass
const float Mb = 2.01410; //Ejectile mass

//	12C(p,d)11C
const float Mx = 12; //Target Mass
float My = 11.01143; // Recoil mass
const float Qgs = -16.496; //Ground State Q-Value (MeV)
//	16O(p,d)15O
//const float Mx = 15.99491; //Target Mass
//float My = 15.00307; // Recoil mass
//const float Qgs = -13.439; //Ground State Q-Value (MeV)
//	32S(p,d)31S
//const float Mx = 31.97207; //Target Mass
//float My = 30.97955; // Recoil mass
//const float Qgs = -12.818; //Ground State Q-Value (MeV)
//	64Zn(p,d)63Zn
//const float Mx = 63.92914; //Target Mass
//float My = 62.93321; // Recoil mass
//const float Qgs = -9.637; //Ground State Q-Value (MeV)

//	(p,t)
//const float Ma = 1.00782; //Beam mass
//const float Mb = 3.01605; //Ejectile mass

//12C(p,t)10C
//const float Mx = 12; //Target Mass
//float My = 10.01685; // Recoil mass
//const float Qgs = -23.359; //Ground State Q-Value (MeV)

//32S(p,t)30S
//const float Mx = 31.97207; //Target Mass
//float My = 29.98490; // Recoil mass
//const float Qgs = -19.617; //Ground State Q-Value (MeV)

//////////////////////////////////////

//Read Arrays, Size = Maximum number of subevents 
int ReadType[1000];
int ReadId[1000];
int ReadChannel[1000];
int ReadValue[1000];

LeafHit Leaf;
BGOHit BGO;

ParticleIn dEin;
ParticleIn E1in;
ParticleIn Upin;

//Limit number of events read for quicker debugging
static int MaxEvents = 100000000;
static int NumberEventsPerPrint = 1000000;

//Thresholds
static int dEThreshold = 10;
static int E1Threshold = 10;
static int UpThreshold = 10;
//static int CloverThreshold = 0;

float CosTheta[24][8];
vector<vector<vector<float>>> Angles(24, vector<vector<float>>(8,vector<float>(3)));

TH2F *CrossTalk = new TH2F("CrossTalk","CrossTalk",1500,0,30000,1500,0,30000);
TH2F *GG = new TH2F("GG","Gamma-Gamma",1024,0,8192,1024,0,8192);
TH2F *GGpart = new TH2F("GGpart","Gamma-Gamma (part)",1024,0,8192,1024,0,8192);
//TH1F *GSingles = new TH1F("GSingles","Gamma Singles",4096,0,8192);
//TH1F *Gdcut = new TH1F("Gdcut","Gammas Deuteron Gated",4096,0,8192);

//////////////////////////////
//		Main function		//
//////////////////////////////

int main(int argc,char **argv)
{
	int StartClock = clock();

	PrintHyperSort("yellow");
	//////////////////////////////////////////////////////////////////////////////////
	//I'm not sure exactly why I need these gSystem->Load(class_cpp.so) lines...	//
	//	but, without these lines I can't use my custom classes as TTree 	//	
	//	branches and have their member variables automatically be leaves.	//
	//										//
	//Wrong	***These shared object files must first be created,			//
	//	1.) Change the include path to class.h in class.cpp to 			//
	//	#include "../include/class.h"						//
	//	2.) Go to the directory with the class.cpp files and type:		//
	//	> root .x class.cpp++							//
	//	This creates a bunch of crap including class_h.so			//
	//	3.)Copy all crap to include folder					//
	//	> mv class_cpp* ../include/.						//
	//										//
	//Right	***These shared object files must first be created,			//
	//	1.) Change the include path to class.h in class.cpp to 			//
	//	#include "../include/class.h"						//
	//	2.) Go to the directory with the class.h files and type:		//
	//	> root .x class.h++							//
	//	This creates a bunch of crap including class_h.so			//
	//										//
	//////////////////////////////////////////////////////////////////////////////////
	gROOT->ProcessLine(".L include/ParticleHit.h++");
	gROOT->ProcessLine(".L include/CloverArray.h++");
	gROOT->ProcessLine(".L include/LeafArray.h++");
	gSystem->Load("include/ParticleHit_h.so");
	gSystem->Load("include/CloverArray_h.so");
	gSystem->Load("include/LeafArray_h.so");
	cout << "\n";
	//////////////////////////////////////////////////////////////////////////////////

	bool TelescopeSuccess = false;
	bool CloverSuccess = false;

	//////////////////////////////////
	//		Fill Angle array		//
	//////////////////////////////////

	Angles = CalculateAngles();

	for(int r = 0;r<24;r++){
		for(int s=0;s<8;s++){
			CosTheta[r][s] = cos((PI/180)*Angles[r][s][0]);
		}
	}

	// Check that the corrent number of arguments were provided.
	if (argc<2)	{
		cout << PrintOutput("Incorrect Number of Arguments!","red") << endl;
		cout << "Try: ./sort run<#>" << endl;
		return 1;
	}

	//Take input and make strings for data file and root file
	char DataFileName[120] = "";
	char RootFileName[120] = "";

	strcat(DataFileName,"../data/");
	strcat(DataFileName,argv[1]);
	strcat(DataFileName,".csd");

	strcat(RootFileName,"RootFiles/");
	strcat(RootFileName,argv[1]);
	strcat(RootFileName,".root");

	// Open the file. Check whether file opened successfully.
	ifstream fin(DataFileName);
	if (!fin.is_open())	{
		cout << PrintOutput("File not found:  ","red") << DataFileName << endl;
		exit(1);
	}

	//Create and Open Root file to store data in. Check for success.
	TFile *RootFile = new TFile(RootFileName,"RECREATE");
	if(!RootFile->IsOpen()){
		printf("Root File did not open!");
		exit(1);
	}

	cout << PrintOutput("Processing: ","green") << argv[1] << endl;
	cout << PrintOutput("Sorting data file : ","green")<<DataFileName<<endl;
	cout << PrintOutput("Creating root file : ","green")<<RootFile->GetName()<<endl;

	TNamed *TD = new TNamed("TargetDistance",Form("%f",TargetDistance));
	TNamed *XO = new TNamed("Xoffset",Form("%f",Xoffset));
	TNamed *YO = new TNamed("Yoffset",Form("%f",Yoffset));
	TNamed *BE = new TNamed("BeamEnergy",Form("%f",BeamEnergy));
	TNamed *MA = new TNamed("Ma",Form("%f",Ma));
	TNamed *MB = new TNamed("Mb",Form("%f",Mb));
	TNamed *MY = new TNamed("My",Form("%f",My));
	TNamed *MX = new TNamed("Mx",Form("%f",Mx));
	TNamed *QV = new TNamed("Qgs",Form("%f",Qgs));

	TD->Write();
	XO->Write();
	YO->Write();
	BE->Write();
	MA->Write();
	MB->Write();
	MY->Write();
	MX->Write();
	QV->Write();

	//////////////////////////
	//	Setup TTree	//
	//////////////////////////

	ParticleHit *dE = new ParticleHit();
	ParticleHit *E1 = new ParticleHit();
	ParticleHit *Up = new ParticleHit();
	ParticleHit *Tel = new ParticleHit();
	CloverArray *Clover = new CloverArray();
	LeafArray *LeafList = new LeafArray();

	TTree *Tree = new TTree("Tree","Data Tree");

	Tree->Branch("dE",&dE);
	Tree->Branch("E1",&E1);
	Tree->Branch("Up",&Up);
	Tree->Branch("Tel",&Tel);
	Tree->Branch("Clover",&Clover);
	Tree->Branch("LeafList",&LeafList);

	cout << PrintOutput("**************************************************************","blue") << endl;
	cout << PrintOutput("**                       Parameters                         **","blue") << endl;
	cout << PrintOutput("**************************************************************","blue") << endl;

	cout<<TD->GetName()<<" = "<<TD->GetTitle()<<endl;
	cout<<XO->GetName()<<" = "<<XO->GetTitle()<<endl;
	cout<<YO->GetName()<<" = "<<YO->GetTitle()<<endl;
	cout<<BE->GetName()<<" = "<<BE->GetTitle()<<endl;
	cout<<MX->GetName()<<" = "<<MX->GetTitle()<<endl;
	cout<<MA->GetName()<<" = "<<MA->GetTitle()<<endl;
	cout<<MB->GetName()<<" = "<<MB->GetTitle()<<endl;
	cout<<MY->GetName()<<" = "<<MY->GetTitle()<<endl;
	cout<<QV->GetName()<<" = "<<QV->GetTitle()<<endl;

	cout << PrintOutput("**************************************************************","blue") << endl;
	cout << PrintOutput("**                Start Event Processing Loop               **","blue") << endl;
	cout << PrintOutput("**************************************************************","blue") << endl;

	int NumberEvents = 0;

	while (!fin.eof()&&fin.good()&&NumberEvents<MaxEvents){

		// Read in the number of SubEvents.
		int nsub=readUInt(fin);
		
		if (nsub>0){
			// Create new Event.
			Event *e;
			e=new Event;
			e->nsub=nsub;//pipe # of sub events into structure e of type EVENT
			e->time=readDouble(fin);//read next element of file which is time
			e->sub=new SubEvent[nsub];//define array SubEvent of type sub in EVENT, length nsub
			
			// Read in each SubEvent.
			for (int i=0;i<nsub;i++){//read in each element of sub event, end defined by length given at start.
				e->sub[i].type=readUChar(fin);
				e->sub[i].id=readUChar(fin);
				e->sub[i].channel=readUShort(fin);
				e->sub[i].value=readInt(fin);

			} //End read sub event loop

			//Fill Read Arrays with sub events
			ReadEvent(e);

			//Print event information
			//printEvent(e);

			//////////////////////////////////////////
			//	Begin subevent sort loop	//
			//////////////////////////////////////////

			ResetInStructs();

			for(int i=0; i<nsub; i++){

				//if(ReadType[i] == 1 && ReadValue[i]!=7680){ //ADC hit and Value not overflow
				if(ReadType[i] == 1 ){ //ADC hit and Value not overflow
					if(ReadId[i] == 1 && ReadValue[i] > dEThreshold){ //Module 1 : dE
						if(ReadChannel[i]<24 && dEin.Ring.Emult<24){
							dEin.Ring.ReadE[dEin.Ring.Emult]=ReadValue[i];
							dEin.Ring.Echan[dEin.Ring.Emult]=ReadChannel[i];
							dEin.Ring.Emult++;
						}else if(dEin.Sector.Emult<8){
							dEin.Sector.ReadE[dEin.Sector.Emult]=ReadValue[i];
							dEin.Sector.Echan[dEin.Sector.Emult]=ReadChannel[i]-24;
							dEin.Sector.Emult++;
						}						
					}else if(ReadId[i] == 2 && ReadValue[i] > E1Threshold){ //Module 2 : E1
						if(ReadChannel[i]<24 && E1in.Ring.Emult<24){
							E1in.Ring.ReadE[E1in.Ring.Emult]=ReadValue[i];
							E1in.Ring.Echan[E1in.Ring.Emult]=ReadChannel[i];
							E1in.Ring.Emult++;
						}else if(E1in.Sector.Emult<8){
							E1in.Sector.ReadE[E1in.Sector.Emult]=ReadValue[i];
							E1in.Sector.Echan[E1in.Sector.Emult]=ReadChannel[i]-24;
							E1in.Sector.Emult++;
						}			
					}else if(ReadId[i] == 3 && ReadValue[i] > UpThreshold){ //Module 3 : Upstream
						if(ReadChannel[i]<24 && Upin.Ring.Emult<24){
							Upin.Ring.ReadE[Upin.Ring.Emult]=ReadValue[i];
							Upin.Ring.Echan[Upin.Ring.Emult]=ReadChannel[i];
							Upin.Ring.Emult++;
						}else if(Upin.Sector.Emult<8){
							Upin.Sector.ReadE[Upin.Sector.Emult]=ReadValue[i];
							Upin.Sector.Echan[Upin.Sector.Emult]=ReadChannel[i]-24;
							Upin.Sector.Emult++;
						}			
					}else if(ReadId[i]==4){ //Module 4 : Clover 1 - 8 
							Leaf.ReadE[Leaf.Emult]=ReadValue[i];
							Leaf.Echan[Leaf.Emult]=ReadChannel[i];
							Leaf.Emult++;
					}else if(ReadId[i]==5 && ReadChannel[i]<16){ //Module 5 : Clover 9 - 11, 13
							Leaf.ReadE[Leaf.Emult]=ReadValue[i];
							Leaf.Echan[Leaf.Emult]=ReadChannel[i]+32;
							Leaf.Emult++;
					}else if( ReadId[i] == 6 && ReadChannel[i]<12){ //Module 6 : BGO
							BGO.ReadE[BGO.Emult]=ReadValue[i];
							BGO.Echan[BGO.Emult]=ReadChannel[i];
							BGO.Emult++;
					}
				}

				if(ReadType[i] == 2 && ReadValue[i]<7680){ //TDC hit
					if(ReadChannel[i] < 32){ //Channel 0 - 31 : dE
						if(ReadChannel[i]<24 && dEin.Ring.Tmult<24){
							dEin.Ring.ReadT[dEin.Ring.Tmult]=ReadValue[i];
							dEin.Ring.Tchan[dEin.Ring.Tmult]=ReadChannel[i];
							dEin.Ring.Tmult++;
						}else if(dEin.Sector.Emult<8){
							dEin.Sector.ReadT[dEin.Sector.Tmult]=ReadValue[i];
							dEin.Sector.Tchan[dEin.Sector.Tmult]=ReadChannel[i]-24;
							dEin.Sector.Tmult++;
						}		
					}else if(ReadChannel[i] < 64){ //Channel 32 - 63 : E1
						if(ReadChannel[i]<56 && E1in.Ring.Tmult<24){
							E1in.Ring.ReadT[E1in.Ring.Tmult]=ReadValue[i];
							E1in.Ring.Tchan[E1in.Ring.Tmult]=ReadChannel[i]-32;
							E1in.Ring.Tmult++;
						}else if(E1in.Sector.Emult<8){
							E1in.Sector.ReadT[E1in.Sector.Tmult]=ReadValue[i];
							E1in.Sector.Tchan[E1in.Sector.Tmult]=ReadChannel[i]-56;
							E1in.Sector.Tmult++;
						}		
					}else if(ReadChannel[i] < 112){ //Channel 64 - 111 : Clovers
						Leaf.ReadT[Leaf.Tmult]=ReadValue[i];
						Leaf.Tchan[Leaf.Tmult]=ReadChannel[i]-64;
						Leaf.Tmult++;
					}else if(ReadChannel[i] < 124){ //Channel 112 - 123 : BGO
						BGO.ReadT[BGO.Tmult]=ReadValue[i];
						BGO.Tchan[BGO.Tmult]=ReadChannel[i]-112;
						BGO.Tmult++;
					}else if(ReadChannel[i]==127){ //Upstream summed time out
						if(Upin.Ring.Tmult<24){
							//Upin.Ring.ReadT[Upin.Ring.Tmult]=ReadValue[i];
							Upin.Ring.Tmult++;
						}
						if(Upin.Sector.Tmult<8){
							//Upin.Sector.ReadT[Upin.Sector.Tmult]=ReadValue[i];
							Upin.Sector.Tmult++;
						}
					}
				}
			}//End subevent sort loop
		
			//////////////////////////////////
			//		Reset event variables	//
			//////////////////////////////////

			TelescopeSuccess=false;
			CloverSuccess=false;

			LeafList->ResetAll();
			Clover->ResetAll();
			dE->ResetAll();
			E1->ResetAll();
			Up->ResetAll();
			Tel->ResetAll();

			//////////////////////////////////////////
			//		Call Detector Processors		//
			//////////////////////////////////////////

			TelescopeSuccess = ProcessSilicon(*dE,*E1,*Up,*Tel);
			CloverSuccess = ProcessClovers(*Clover, *LeafList);

			//////////////////////////////////////////////////////////
			//		3/2/2018 Added to make gamma-gamma plots		//
			//////////////////////////////////////////////////////////

			double g1=0,g2=0;	

			if(Clover->GetMult()==2){
				for(int i=0;i<12;i++){
					if(Clover->GetEnergy(i)>0 && g1==0){
						g1=Clover->GetDopplerEnergy(i);
					}else if(Clover->GetEnergy(i)>0 && g1>0 && g2==0){
						g2=Clover->GetDopplerEnergy(i);
					}
				}
				if(g1!=g2){
					GG->Fill(g1,g2);
					GG->Fill(g2,g1);
					if(Tel->GetPIDlinear()>20000&&Tel->GetPIDlinear()<29000){
						GGpart->Fill(g1,g2);
						GGpart->Fill(g2,g1);
					}
				}
			}
/*
			//Gamma singles 3/5/2018

			for(int i=0;i<Clover->GetMult();i++){
				if(Clover->GetEnergy(i)>0){
					GSingles->Fill(Clover->GetEnergy(i));
						if(Tel->GetPIDlinear()>20000&&Tel->GetPIDlinear()<29000){
							Gdcut->Fill(Clover->GetEnergy(i));
						}
				}
			}
*/
			////////////////////////////////////////////////////////////


			//////////////////////////////////////////////////
			//				Calculate Angle	alpha			//
			//						and						//
			//				Apply Doppler Correction		//
			//////////////////////////////////////////////////
			//Find the angle between the recoil and the gamma-ray
			//Theta : Polar (0 to pi)
			//Phi : azimuthal (0 to 2pi)

			float RecoilPhi, RecoilTheta;
			float CosAlpha, LeafTheta, LeafPhi, Beta, DopplerCorrectedEnergy;
			float Xrec, Yrec, Zrec, Xdet, Ydet, Zdet;
			float Top, Bottom;

			float PhiAngles[8] = {112.5,157.5,202.5,247.5,292.5,337.5,22.5,67.5}; //counter-clockwise sector ordering (0 and 7 at bottom)
			//							C0		C1		C2		C3		C4		C5		C6		C7		C8		C9		C10		C11
			float CloverTheta[12] = {	135.0, 	90.0,  	45.0,  	45.0, 	90.0, 	135.0, 	90.0, 	45.0, 	90.0, 	135.0,	90.0, 	90.0};
			float CloverPhi[12] =   {	0.0,	0.0,	0.0,	180.0,	180.0,	180.0, 	45.0,	90.0,	135.0,	90.0,	315.0,	225.0};

			//Cabled by Color
			float LeafOffsetTheta[12][4] =	{	
												{6.29,-7.10-7.10,6.29},		//C0
												{6.74,-6.74,-6.74,6.74},	//C1 
												{7.10,-6.29,-6.29,7.10},	//C2

												{-6.29,7.10,7.10,-6.29},	//C3
												{-6.74,6.74,6.74,-6.74},	//C4
												{-7.10,6.29,6.29,-7.10},	//C5

												{6.74,-6.74,-6.74,6.74},	//C6
												{7.10,7.10,-6.29,-6.29},	//C7
												{-6.74,-6.74,6.74,6.74},	//C8
												{-7.10,-7.10,6.29,6.29}, 	//C9

												{6.74,-6.74,-6.74,6.74}, 	//C10
												{-6.74,6.74,6.74,-6.74} 	//C11
											};

			float LeafOffsetPhi[12][4] =	{	
												{10.82,8.56,-8.56,-10.82}, 	//C0
												{6.79,6.79,-6.79,-6.79}, 	//C1 
												{8.56,10.82,-10.82,-8.56}, 	//C2

												{-10.82,-8.56,8.56,10.82}, 	//C3
												{-6.79,-6.79,6.79,6.79}, 	//C4
												{-8.56,-10.82,10.82,8.56}, 	//C5

												{6.79,6.79,-6.79,-6.79}, 	//C6
												{-8.56,8.56,10.82,-10.82}, 	//C7
												{6.79,-6.79,-6.79,6.79}, 	//C8
												{8.56,-8.56,-10.82,10.82}, 	//C9

												{6.79,6.79,-6.79,-6.79}, 	//C10
												{-6.79,	-6.79,6.79,6.79} 	//C11
											};

			RecoilPhi = PhiAngles[dE->GetSector()];
			RecoilTheta = Tel->GetRecoilAngle();

			for(int i=0;i<12;i++){	
				LeafTheta 	= CloverTheta[Clover->GetId(i)] + LeafOffsetTheta[Clover->GetId(i)][Clover->GetLeaf(i)];
				LeafPhi 	= CloverPhi[Clover->GetId(i)] + LeafOffsetPhi[Clover->GetId(i)][Clover->GetLeaf(i)];
				if(LeafPhi < 0){
					LeafPhi = 360+LeafPhi;
				}

				if(Clover->GetEnergy(i)>0){
					//Get x,y,z components of unit vector in recoil direction
					Xrec = sin((PI/180.0)*RecoilTheta)*cos((PI/180.0)*RecoilPhi);
					Yrec = sin((PI/180.0)*RecoilTheta)*sin((PI/180.0)*RecoilPhi);
					Zrec = cos((PI/180.0)*RecoilTheta);
					//Get x,y,z components of unit vector in clover leaf direction
					Xdet = sin((PI/180.0)*LeafTheta)*cos((PI/180.0)*LeafPhi);
					Ydet = sin((PI/180.0)*LeafTheta)*sin((PI/180.0)*LeafPhi);
					Zdet = cos((PI/180.0)*LeafTheta);
					//Compute dot product to get cosine of angle between recoil and clover leaf
					CosAlpha = Xrec*Xdet + Yrec*Ydet + Zrec*Zdet;
					Clover->SetCosAlpha(i,CosAlpha);
					//Compute the beta (v/c) value of the recoil. This assumes gamma emission happens immediately following transfer
					Top = sqrt(2*Ma*BeamEnergy)-sqrt(2*Mb*(Tel->GetEnergy()/1000.0))*cos((PI/180.0)*Tel->GetAngle()); //Units (MeV*u)^1/2
					Bottom = cos((PI/180.0)*RecoilTheta);
					Beta = (0.03276507)*(1/My)*(Top/Bottom);
					//Compute Doppler corrected energy
					DopplerCorrectedEnergy = Clover->GetEnergy(i) * ( ( 1 - (Beta*CosAlpha) ) / (sqrt(1-(Beta*Beta))) );
					Clover->SetDopplerEnergy(i,DopplerCorrectedEnergy);
				}else{ //If no energy in the clover set cosine alpha to -2 and Doppler corrected energy to zero
					Clover->SetCosAlpha(i,-2);
					Clover->SetDopplerEnergy(i,0.0);
				}
			}

			//////////////////////////
			//		Fill Tree		//
			//////////////////////////

			//Define condition for putting the event into the tree
			if(TelescopeSuccess){
			//if(CloverSuccess){
			//if(TelescopeSuccess && CloverSuccess){
				Tree->Fill();
			}

			// Clear the event.
			delete [] e->sub;
			delete e;
			
			// Increment the event counter.
			NumberEvents++;

			int RunClock = clock();
			if(NumberEvents%NumberEventsPerPrint==0){
				cout<<PrintOutput("Events Processed","green")<<" = "<<NumberEvents<<"\t";
				cout<<PrintOutput("Time","green")<<" = "<<Form("%.02f",(RunClock-StartClock)/double(CLOCKS_PER_SEC))<<" seconds"<<endl;
			}	
		}//End of Event (if nsub>0)
	}//End of while loop over file	

	//Write objects to Root file and close
	CrossTalk->Write();
	GG->Write();
	GGpart->Write();
	//GSingles->Write();
	//Gdcut->Write();
	Tree->Write();
	RootFile->Close();

	//Get end run time
	int StopClock = clock();
	double RunTime = (StopClock-StartClock)/double(CLOCKS_PER_SEC);

	//Print Diagnostics
	cout << PrintOutput("**************************************************************","blue") << endl;
	cout << PrintOutput("**                         Finished                         **","blue") << endl;
	cout << PrintOutput("**************************************************************","blue") << endl;
	cout << PrintOutput("Created root file : ","green")<<RootFileName<<endl;
	cout << PrintOutput("Sort time = ","green") << RunTime << " seconds" << endl;
	cout << PrintOutput("Events Processed = ","green")<<NumberEvents<<"\t"<<(double)NumberEvents/RunTime<<" Events/second"<<endl;
	//cout << "Sub Events Processed = "<<NumberSubEvents<<"\t"<<(double)NumberSubEvents/RunTime <<" per second"<<endl;
	cout << PrintOutput("**************************************************************","blue") << endl;
	return 0;
}


