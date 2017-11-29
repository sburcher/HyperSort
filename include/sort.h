// Standard template library include files.
#include <fstream>
using namespace std;

// Standard library include files.
#include <iostream>
#include <cstdlib>
#include <ctime>

//Include root libraries
#include "TROOT.h"
#include "TFile.h"
#include "TH1.h"
#include "TH2.h"
#include "TTree.h"

//Declare Variables
int ParticleThreshold = 300;

int NumberEvents = 0;
int NumberSubEvents = 0;

//Declare Arrays
int dEhit[8];
int Ehit[8];

int GammaHit[48];
int BGOhit[12];

// ***************
// Event structure
// ***************

struct SubEvent
{
	// Module type.
	unsigned char type;
	
	// Module ID.
	unsigned char id;
	
	// Module channel.
	unsigned short channel;
	
	// Channel value.
	int value;
};

struct Event
{
	// Number of SubEvents.
	int nsub;
	
	// Time stamp.
	double time;
	
	// SubEvent array.
	SubEvent *sub;
};

// **************
// Read functions
// **************
inline unsigned char readUChar(ifstream& fin)
{
	// Read in unsigned character.
	unsigned char value=0;
	fin.read((char*)&value,1);
	return value;
}

inline unsigned short readUShort(ifstream& fin)
{
	// Read in unsigned short integer.
	unsigned short value=0;
	fin.read((char*)&value,2);
	return value;
}

inline unsigned int readUInt(ifstream& fin)
{
	// Read in unsigned integer.
	unsigned int value=0;
	fin.read((char*)&value,4);
	return value;
}

inline int readInt(ifstream& fin)
{
	// Read in integer.
	int value=0;
	fin.read((char*)&value,4);
	return value;
}

inline double readDouble(ifstream& fin)
{
	// Read in double.
	double value=0.0;
	fin.read((char*)&value,8);
	return value;
}

// ***************
// Print Functions
// ***************

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




