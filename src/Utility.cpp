// Standard template library include files.
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cstdlib>

//My Includes
#include "Utility.h"
#include "Sort.h"

using namespace std;

void ReadEvent(Event *e){

	for(int i=0 ; i < e->nsub ; i++){
		SubEvent &se=e->sub[i];
		ReadType[i] = se.type;
		ReadId[i] = se.id;
		ReadChannel[i] = se.channel;
		ReadValue[i] = se.value;

	}
}
////////////////////
// Print Functions
////////////////////

void printEvent(Event* e)
{
	// Print out the event.
	printf("Sub events: %d\n",e->nsub);
	printf("Time: %0.9f s\n",e->time);
	for (int i=0;i<e->nsub;i++)	{
		SubEvent &se=e->sub[i];
			//printf("\n");
			//printf("Time: %0.9f s\n",e->time);
			printf("Type: %d  ID: %d  Channel: %d  Value: %d\n",se.type,se.id,se.channel,se.value);
	}
}

string PrintOutput(string Output, string Color){

	int ColorCode = 0;

	if(Color.compare("red")==0){
		ColorCode = 31;
	}else if(Color.compare("green")==0){
		ColorCode = 32;
	}else if(Color.compare("yellow")==0){
		ColorCode = 33;
	}else if(Color.compare("blue")==0){
		ColorCode = 34;
	}else{
		cout << Form("Output Color not recognized : %s",Color.c_str()) << endl;
		return Form("%s",Output.c_str());
	}

	return Form("\033[1;%dm%s\033[0m",ColorCode,Output.c_str());

}

////////////////////
// Read functions
///////////////////

unsigned char readUChar(ifstream& fin)
{
	// Read in unsigned character.
	unsigned char value=0;
	fin.read((char*)&value,1);
	return value;
}

unsigned short readUShort(ifstream& fin)
{
	// Read in unsigned short integer.
	unsigned short value=0;
	fin.read((char*)&value,2);
	return value;
}

unsigned int readUInt(ifstream& fin)
{
	// Read in unsigned integer.
	unsigned int value=0;
	fin.read((char*)&value,4);
	return value;
}

int readInt(ifstream& fin)
{
	// Read in integer.
	int value=0;
	fin.read((char*)&value,4);
	return value;
}

double readDouble(ifstream& fin)
{
	// Read in double.
	double value=0.0;
	fin.read((char*)&value,8);
	return value;
}


void ResetInStructs(){
			for(int i=0;i<24;i++){
				dEin.Ring.ReadE[i]=0;
				dEin.Ring.ReadT[i]=0;
				dEin.Ring.Echan[i]=-1;
				dEin.Ring.Tchan[i]=-1;
				dEin.Ring.RawE[i]=0;
				dEin.Ring.Time[i]=0;
				dEin.Ring.Eid[i]=-1;
				dEin.Ring.Tid[i]=-1;
				dEin.Ring.Energy[i]=0;

				E1in.Ring.ReadE[i]=0;
				E1in.Ring.ReadT[i]=0;
				E1in.Ring.Echan[i]=-1;
				E1in.Ring.Tchan[i]=-1;
				E1in.Ring.RawE[i]=0;
				E1in.Ring.Time[i]=0;
				E1in.Ring.Eid[i]=-1;
				E1in.Ring.Tid[i]=-1;
				E1in.Ring.Energy[i]=0;

				Upin.Ring.ReadE[i]=0;
				Upin.Ring.ReadT[i]=0;
				Upin.Ring.Echan[i]=-1;
				Upin.Ring.Tchan[i]=-1;
				Upin.Ring.RawE[i]=0;
				Upin.Ring.Time[i]=0;
				Upin.Ring.Eid[i]=-1;
				Upin.Ring.Tid[i]=-1;
				Upin.Ring.Energy[i]=0;

			}

			for(int i=0;i<8;i++){
				dEin.Sector.ReadE[i]=0;
				dEin.Sector.ReadT[i]=0;
				dEin.Sector.Echan[i]=-1;
				dEin.Sector.Tchan[i]=-1;
				dEin.Sector.RawE[i]=0;
				dEin.Sector.Time[i]=0;
				dEin.Sector.Eid[i]=-1;
				dEin.Sector.Tid[i]=-1;
				dEin.Sector.Energy[i]=0;

				E1in.Sector.ReadE[i]=0;
				E1in.Sector.ReadT[i]=0;
				E1in.Sector.Echan[i]=-1;
				E1in.Sector.Tchan[i]=-1;
				E1in.Sector.RawE[i]=0;
				E1in.Sector.Time[i]=0;
				E1in.Sector.Eid[i]=-1;
				E1in.Sector.Tid[i]=-1;
				E1in.Sector.Energy[i]=0;

				Upin.Sector.ReadE[i]=0;
				Upin.Sector.ReadT[i]=0;
				Upin.Sector.Echan[i]=-1;
				Upin.Sector.Tchan[i]=-1;
				Upin.Sector.RawE[i]=0;
				Upin.Sector.Time[i]=0;
				Upin.Sector.Eid[i]=-1;
				Upin.Sector.Tid[i]=-1;
				Upin.Sector.Energy[i]=0;
			}

			for(int i=0;i<48;i++){
				Leaf.ReadE[i]=0;
				Leaf.ReadT[i]=0;
				Leaf.Echan[i]=-1;
				Leaf.Tchan[i]=-1;
				Leaf.Energy[i]=0;
				Leaf.Time[i]=0;
				Leaf.Eid[i]=-1;
				Leaf.Tid[i]=-1;
			}

			for(int i=0;i<12;i++){
				BGO.ReadE[i]=0;
				BGO.ReadT[i]=0;
				BGO.Echan[i]=-1;
				BGO.Tchan[i]=-1;
				BGO.Energy[i]=0;
				BGO.Time[i]=0;
				BGO.Eid[i]=-1;
				BGO.Tid[i]=-1;
			}

			dEin.Ring.Emult=0;
			dEin.Ring.Tmult=0;
			dEin.Sector.Emult=0;
			dEin.Sector.Tmult=0;
			E1in.Ring.Emult=0;
			E1in.Ring.Tmult=0;
			E1in.Sector.Emult=0;
			E1in.Sector.Tmult=0;
			Upin.Ring.Emult=0;
			Upin.Ring.Tmult=0;
			Upin.Sector.Emult=0;
			Upin.Sector.Tmult=0;
			Leaf.Emult=0;
			Leaf.Tmult=0;
			BGO.Emult=0;
			BGO.Tmult=0;

}


//std::vector<std::vector<std::vector<float>>> CalculateAngles(){ //Use x and y offset
vector<vector<vector<float>>> CalculateAngles(){ //Use x and y offset

	float FirstRingHeight = 11;
	float RingPitch = 1;

	vector<vector<vector<float>>> fAngles(24, vector<vector<float>>(8,vector<float>(3)));

	float Radius[24] = {0};
	float Phi[8] = {0,PI/4,PI/2,3*PI/4,PI,5*PI/4,3*PI/2,7*PI/4};

	float r1[24][8] = {0};
	float r2[24][8] = {0};
	float phi1[24][8] = {0};
	float phi2[24][8] = {0};

	float rm[24][8] = {0};
	float phim[24][8] = {0};

	float rprime = 0;
	float xprime = 0;
	float yprime = 0;

	float c1,c2,c3,c4;

	for(int r=0; r<24; r++){
		Radius[r] = FirstRingHeight+r;
		for(int s=0; s<8; s++){
			r1[r][s]=Radius[r];
			phi1[r][s]=Phi[s];

			r2[r][s]=Radius[r]+RingPitch;
			phi2[r][s]=Phi[s]+PI/4;

			rm[r][s]=Radius[r]+0.5*RingPitch;
			phim[r][s]=Phi[s]+PI/8;

			//Compute angle for central point
			xprime = rm[r][s]*cos(phim[r][s])-Xoffset;
			yprime = rm[r][s]*sin(phim[r][s])-Yoffset;
			rprime = sqrt(xprime*xprime+yprime*yprime);
			fAngles[r][s][0] = (180/PI)*atan(rprime/TargetDistance);
			//Corner 1
			xprime = r1[r][s]*cos(phi1[r][s])-Xoffset;
			yprime = r1[r][s]*sin(phi1[r][s])-Yoffset;
			rprime = sqrt(xprime*xprime+yprime*yprime);
			c1 = (180/PI)*atan(rprime/TargetDistance);
			//Corner 2
			xprime = r1[r][s]*cos(phi2[r][s])-Xoffset;
			yprime = r1[r][s]*sin(phi2[r][s])-Yoffset;
			rprime = sqrt(xprime*xprime+yprime*yprime);
			c2 = (180/PI)*atan(rprime/TargetDistance);
			//Corner 3
			xprime = r2[r][s]*cos(phi2[r][s])-Xoffset;
			yprime = r2[r][s]*sin(phi2[r][s])-Yoffset;
			rprime = sqrt(xprime*xprime+yprime*yprime);
			c3 = (180/PI)*atan(rprime/TargetDistance);
			//Corner 4
			xprime = r2[r][s]*cos(phi1[r][s])-Xoffset;
			yprime = r2[r][s]*sin(phi1[r][s])-Yoffset;
			rprime = sqrt(xprime*xprime+yprime*yprime);
			c4 = (180/PI)*atan(rprime/TargetDistance);

			fAngles[r][s][1] = (c1+c2)/2;	
			fAngles[r][s][2] = (c3+c4)/2;	

		}
	}

	return fAngles;
}

/*

std::vector<std::vector<std::vector<float>>> CalculateAngles(){ //Use theta and phi offset

	float FirstRingHeight = 11;
	float RingPitch = 1;

	vector<vector<vector<float>>> fAngles(24, vector<vector<float>>(8,vector<float>(3)));

	float Radius[24] = {0};
	float Phi[8] = {0,PI/4,PI/2,3*PI/4,PI,5*PI/4,3*PI/2,7*PI/4};

	float r1[24][8] = {0};
	float r2[24][8] = {0};
	float phi1[24][8] = {0};
	float phi2[24][8] = {0};

	float rm[24][8] = {0};
	float phim[24][8] = {0};

	float Roff[3] = {static_cast<float>(sin((PI/180)*ThetaOffset)*cos(PhiOffset)),static_cast<float>(sin((PI/180)*ThetaOffset)*sin(PhiOffset)),static_cast<float>(cos((PI/180)*ThetaOffset))};

	float R[3] = {0,0,TargetDistance};
	float Rmag = 0;

	float c1,c2,c3,c4;

	for(int r=0; r<24; r++){
		Radius[r] = FirstRingHeight+r;
		for(int s=0; s<8; s++){
			//	Setup elements coordinates	//
			r1[r][s]=Radius[r];
			phi1[r][s]=Phi[s];

			r2[r][s]=Radius[r]+RingPitch;
			phi2[r][s]=Phi[s]+PI/4;

			rm[r][s]=Radius[r]+0.5*RingPitch;
			phim[r][s]=Phi[s]+PI/8;

			// 	Find (x,y) of center point of element	//
			R[0] = rm[r][s]*cos(phim[r][s]);
			R[1] = rm[r][s]*sin(phim[r][s]);
			//	Compute magnitude of vector to element	//
			Rmag = sqrt(R[0]*R[0]+R[1]*R[1]+R[2]*R[2]);
			//	Use dot product to calc angle between element and new beam axis	//
			fAngles[r][s][0]= (180/PI)*acos( (R[0]*Roff[0] + R[1]*Roff[1] + R[2]*Roff[2]) / Rmag );
	
		}
	}

	return fAngles;
}
*/

void PrintHyperSort(string fColor){

	cout << "\n";
	cout << PrintOutput(" **    **  **      **  *******    ********  *******      *****      *****    *******    **********\n",fColor);
	cout << PrintOutput(" **    **   **    **   ********   ********  ********    *******    *******   ********   **********\n",fColor);
	cout << PrintOutput(" **    **    **  **    **     **  **        **     **  **     **  **     **  **     **      **    \n",fColor);
	cout << PrintOutput(" **    **     ****     **     **  **        **     **  **         **     **  **     **      **    \n",fColor);
	cout << PrintOutput(" ********      **      ********   ********  ********    ******    **     **  ********       **    \n",fColor);
	cout << PrintOutput(" ********      **      *******    ********  *******      ******   **     **  *******        **    \n",fColor);
	cout << PrintOutput(" **    **      **      **         **        **  **            **  **     **  **  **         **    \n",fColor);
	cout << PrintOutput(" **    **      **      **         **        **   **    **     **  **     **  **   **        **    \n",fColor);
	cout << PrintOutput(" **    **      **      **         ********  **    **    *******    *******   **    **       **    \n",fColor);
	cout << PrintOutput(" **    **      **      **         ********  **     **    *****      *****    **     **      **    \n",fColor);
	cout << PrintOutput("                               > > The Hyperion Array Sort Code < <                               \n",fColor);
	cout << "\n";
}




















