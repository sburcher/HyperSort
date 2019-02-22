#ifndef DECLARATIONS_H
#define DECLARATIONS_H


//Set to 1 to select which energy to use in dE+E (only choose one option)
#define USE_SECTOR_ENERGY 1
#define USE_RING_ENERGY 0
#define USE_AVG_ENERGY 0

#define USE_SECTOR_TIME 1


///////////////////////////////
//     Declare Variables     //
///////////////////////////////



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

struct RingIn{
	//All values read in
	float ReadE[24];
	float ReadT[24];
	int Echan[24];
	int Tchan[24];

	//Values after require E and T
	float RawE[24];
	float Time[24];
	int Eid[24];
	int Tid[24];

	//Energy after calibration
	float Energy[24];
	
	int Emult;
	int Tmult;
};

struct SectorIn{
	//All values read in
	float ReadE[8];
	float ReadT[8];
	int Echan[8];
	int Tchan[8];

	//Values after require E and T
	float RawE[8];
	float Time[8];
	int Eid[8];
	int Tid[8];

	//Energy after calibration
	float Energy[8];
	
	int Emult;
	int Tmult;
};

struct ParticleIn{

	RingIn Ring;
	SectorIn Sector;

};

struct LeafHit{
	float ReadE[48];
	float ReadT[48];
	int Echan[48];
	int Tchan[48];

	float RawE[48];
	float Time[48];
	int Eid[48];
	int Tid[48];

	float Energy[48];

	int Emult;
	int Tmult;

};

struct BGOHit{
	float ReadE[12];
	float ReadT[12];

	int Echan[12];
	int Tchan[12];

	float Energy[12];
	float Time[12];
	int Eid[12];
	int Tid[12];

	int Emult;
	int Tmult;

};



#endif


