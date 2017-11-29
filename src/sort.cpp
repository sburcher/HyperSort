#include "sort.h"



// *************
// Main function
// *************

int main(int argc,char **argv)
{
	//
	int StartClock = clock();

	// Check that the corrent number of arguments were provided.
	if (argc<2)	{
		printf("Incorrect number of arguments:\n");
		printf("csort (filename)\n");
		return 1;
	}
	
	// Open the file.
	ifstream fin(argv[1]);

	// Check whether file opened successfully.
	if (!fin.is_open())	{
		printf("File not found: %s\n",argv[1]);
		exit(1);
	}

	//Create and Open Root file to store data in
	TFile *RootFile = new TFile("RootFiles/Test.root","RECREATE");
	if(!RootFile->IsOpen()){
		printf("Root File did not open!");
	}


	////////////////////////////////////
	//Declare Histograms for data
	////////////////////////////////////

	//Silicon
	TH1F *dE[32];
	TH1F *E[32];
	for(int i=0;i<32;i++){
		if(i<24){//Rings
			dE[i] = new TH1F((char *)Form("dE:R%d",i),(char *)Form("dE : Ring %d",i),8192,0,8192);
			E[i] = new TH1F((char *)Form("E:R%d",i),(char *)Form("E : Ring %d",i),8192,0,8192);
		}else{//Sectors	
			dE[i] = new TH1F((char *)Form("dE:S%d",i-24),(char *)Form("dE : Ring %d",i),8192,0,8192);
			E[i] = new TH1F((char *)Form("E:S%d",i-24),(char *)Form("E : Ring %d",i),8192,0,8192);
		}
	}

	TH1F *dETotal = new TH1F("dETotal","dE Total",8192,0,8192);
	TH1F *ETotal = new TH1F("ETotal","E Total",8192,0,8192);

	TH2F *PID = new TH2F("PID","PID",8192,0,8192,8192,0,8192);

	//Clovers
	TH1F *Clover[48];
	for(int i=0;i<48;i++){
		if((int)i/4+1 == 12){//Clover 13 not 12
			Clover[i] = new TH1F((char *)Form("C13:L%d",i%4+1),(char *)Form("Clover 13 : Leaf %d",i%4+1),8192,0,8192);
		}else{
			Clover[i] = new TH1F((char *)Form("C%d:L%d",(int)i/4+1,i%4+1),(char *)Form("Clover %d : Leaf %d",1+(int)i/4,i%4+1),8192,0,8192);
		}
	}

	TH2F *GG = new TH2F("GG","Gamma-Gamma",8192,0,8192,8192,0,8192);

	//BGO
	TH1F *BGO[12];
	for(int i=0;i<12;i++){
		BGO[i] = new TH1F((char *)Form("BGO%d",i+1),(char *)Form("BGO %d",i+1),8192,0,8192);
	}

	///////////////////////////////////////////////
	//End Declarations
	///////////////////////////////////////////////

	//TTree *Tree = new TTree("Tree","Test Tree");
	//Event *e=new Event;
	//Tree->Branch("Event Branch", "Event", &e);
	
	// Cycle through file.
	int ecount=0;
	
	while (!fin.eof()&&fin.good())	{
		// Read in the number of SubEvents.
		int nsub=readUInt(fin);//read start of event which is # of sub events

		//printf("Event %d , subevents = %d\n",ecount,nsub);

		// Make sure read was successful.
		if (nsub>0)	{
			// Create new Event.
			Event *e=new Event;
			e->nsub=nsub;//pipe # of sub events into structure e of type EVENT
			e->time=readDouble(fin);//read next element of file which is time
			e->sub=new SubEvent[nsub];//define array SubEvent of type sub in EVENT, length nsub

			//printf("\nSub Events = %d\n",nsub);
			//printf("Time = %f\n",e->time);

			//Reset dEHit and EHit
			for(int i=0;i<8;i++){
				dEhit[i]=-1;
				Ehit[i]=-1;
			}

			//Reset Gamma Gamma hit
			for(int i=0;i<48;i++){
				GammaHit[i]=-1;
			}

			//Reset BGO hit
			for(int i=0;i<12;i++){
				BGOhit[i]=-1;
			}

			// Read in each SubEvent.
			for (int i=0;i<nsub;i++){//read in each element of sub event, end defined by length given at start.
				e->sub[i].type=readUChar(fin);
				e->sub[i].id=readUChar(fin);
				e->sub[i].channel=readUShort(fin);
				e->sub[i].value=readInt(fin);
/*
				//Print out sub event information
				if(e->sub[i].value > ParticleThreshold){
					if(e->sub[i].type == 1){
						printf("ADC : Module = %d Chan = %d Value = %d\n",e->sub[i].id,e->sub[i].channel,e->sub[i].value);
					}else{
						printf("TDC : Chan = %d Value = %d\n",e->sub[i].channel,e->sub[i].value);
					}
				}
*/
				//If hit was in a sector store the value
				if(e->sub[i].type == 1 && e->sub[i].value != 7680){//Hit in ADC and Not overflow
					if(e->sub[i].id == 1 || e->sub[i].id == 2){//Hit in dE or E
						if(e->sub[i].channel > 23 && e->sub[i].channel < 32){//Hit in sector
							if(e->sub[i].id == 1){
								dEhit[e->sub[i].channel-23]=e->sub[i].value;
							}else{
								Ehit[e->sub[i].channel-23]=e->sub[i].value;
							}	
						}
					}
					if(e->sub[i].id == 4){//Hit in clover 1-8
						GammaHit[e->sub[i].channel]=e->sub[i].value;
					}
					if(e->sub[i].id == 5){//Hit in clover 9-11-13
						GammaHit[e->sub[i].channel+32]=e->sub[i].value;
					}
					if(e->sub[i].id == 6){//Hit in BGO
						BGOhit[e->sub[i].channel]=e->sub[i].value;
					}
				}
			}

			//Fill PID from correlated sector hits
			for(int i=0;i<8;i++){
				if(dEhit[i] > 0 && Ehit[i] >0){
					PID->Fill(Ehit[i],dEhit[i]);
				}
			}

			//Fill Gamma-Gamma spectrum
			for(int i=0;i<48;i++){
				if(GammaHit[i] > 0 && BGOhit[(int)i/4] == -1){
					for(int j=0;j<48;j++){
						if(i != j && GammaHit[j] > 0 && BGOhit[(int)j/4] == -1){
							GG->Fill(GammaHit[i],GammaHit[j]);
						}
					}
				}
			}

			//Tree->Fill();
			// Display the event data.
			// This is where you should sort the event.

			//printEvent(e);

			for (int i=0;i<nsub;i++){
				
				if(e->sub[i].type == 1 && e->sub[i].value != 7680) { //Is this an ADC event
					if(e->sub[i].id == 1 && e->sub[i].channel < ParticleThreshold) { //Module 1 : dE
						dE[e->sub[i].channel]->Fill(e->sub[i].value);
						dETotal->Fill(e->sub[i].value);
					}
					if(e->sub[i].id == 2 && e->sub[i].channel < ParticleThreshold) { //Module 2 : E
						E[e->sub[i].channel]->Fill(e->sub[i].value);
						ETotal->Fill(e->sub[i].value);
					}
					if(e->sub[i].id == 4) { //Module 4 : Clover 1-8
						if(e->sub[i].channel < 4 && BGOhit[0] == -1){//Hit in Clover 1 and No BGO 1
							Clover[e->sub[i].channel]->Fill(e->sub[i].value);
						}else if(e->sub[i].channel < 8 && BGOhit[1] == -1){//Hit in Clover 2 and No BGO 2
							Clover[e->sub[i].channel]->Fill(e->sub[i].value);
						}else if(e->sub[i].channel < 12 && BGOhit[2] == -1){//Hit in Clover 3 and No BGO 3
							Clover[e->sub[i].channel]->Fill(e->sub[i].value);
						}else if(e->sub[i].channel < 16 && BGOhit[3] == -1){//Hit in Clover 4 and No BGO 4
							Clover[e->sub[i].channel]->Fill(e->sub[i].value);
						}else if(e->sub[i].channel < 20 && BGOhit[4] == -1){//Hit in Clover 5 and No BGO 5
							Clover[e->sub[i].channel]->Fill(e->sub[i].value);
						}else if(e->sub[i].channel < 24 && BGOhit[5] == -1){//Hit in Clover 6 and No BGO 6
							Clover[e->sub[i].channel]->Fill(e->sub[i].value);
						}else if(e->sub[i].channel < 28 && BGOhit[6] == -1){//Hit in Clover 7 and No BGO 7
							Clover[e->sub[i].channel]->Fill(e->sub[i].value);
						}else if(e->sub[i].channel < 28 && BGOhit[7] == -1){//Hit in Clover 8 and No BGO 8
							Clover[e->sub[i].channel]->Fill(e->sub[i].value);
						}
					}
					if(e->sub[i].id == 5 && e->sub[i].channel < 16) { //Module 5 : Clover 9-11,13
						if(e->sub[i].channel < 4 && BGOhit[0] == 0){//Hit in Clover 9 and No BGO 9
							Clover[e->sub[i].channel+32]->Fill(e->sub[i].value);
						}else if(e->sub[i].channel < 8 && BGOhit[1] == -1){//Hit in Clover 10 and No BGO 10
							Clover[e->sub[i].channel+32]->Fill(e->sub[i].value);
						}else if(e->sub[i].channel < 12 && BGOhit[2] == -1){//Hit in Clover 11 and No BGO 11
							Clover[e->sub[i].channel+32]->Fill(e->sub[i].value);
						}else if(e->sub[i].channel < 16 && BGOhit[3] == -1){//Hit in Clover 13 and No BGO 13
							Clover[e->sub[i].channel+32]->Fill(e->sub[i].value);
						}
					}
					if(e->sub[i].id == 6 && e->sub[i].channel < 12) { //Module 6 : BGO 1-12
						BGO[e->sub[i].channel]->Fill(e->sub[i].value);
					}
				}
			}			


			// Clear the event.
			delete [] e->sub;
			delete e;
			
			// Increment the event counter.
			ecount++;
			NumberEvents++;
			NumberSubEvents = NumberSubEvents+nsub;
		}
	}	

	//Save Histograms to Root file and close
	RootFile->Write();
	RootFile->Close();




	//Get end run time
	int StopClock = clock();
	double RunTime = (StopClock-StartClock)/double(CLOCKS_PER_SEC);

	//Print Diagnostics
	cout << "**************************************************************" << endl;
	cout << "Run time = " << RunTime << " seconds" << endl;
	cout << "Events Processed = "<<NumberEvents<<"\t"<<(double)NumberEvents/RunTime<<" Events per second"<<endl;
	//cout << "Sub Events Processed = "<<NumberSubEvents<<"\t"<<(double)NumberSubEvents/RunTime <<" per second"<<endl;
	cout << "**************************************************************" << endl;
	return 0;
}


