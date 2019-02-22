#ifndef SORT_H
#define SORT_H

// Standard template library include files.
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

//Include root libraries
#include "TROOT.h"
#include "TFile.h"
#include "TH1.h"
#include "TH2.h"
#include "TTree.h"
#include "TCutG.h"
#include "TCanvas.h"
#include "TSystem.h"
#include "TRint.h"
#include "TObject.h"

#include "Declarations.h"
#include "ParticleHit.h"
#include "CloverArray.h"
#define PI 3.14159265

extern int ReadType[1000];
extern int ReadId[1000];
extern int ReadChannel[1000];
extern int ReadValue[1000];

extern ParticleIn dEin;
extern ParticleIn E1in;
extern ParticleIn Upin;

extern LeafHit Leaf;
extern BGOHit BGO;

extern float CosTheta[24][8];

extern const float TargetDistance,Xoffset,Yoffset; //mm
//static float ThetaOffset = 2.2; //degrees
//static float PhiOffset = 3.9; //radians

extern vector<vector<vector<float>>> Angles;

extern const float BeamEnergy,Ma,Mb,Mx,Qgs;
extern float My;
extern TH2F *CrossTalk;

#endif



























