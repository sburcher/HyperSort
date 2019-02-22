#include "../include/ParticleHit.h" //Use when generating shared object file with root (see top of main())
//#include "ParticleHit.h"

#include "TObject.h"

//ClassImp(ParticleHit)

//Constructor
ParticleHit::ParticleHit() { }

//Setters
void ParticleHit::SetEnergy(float fEnergy){
	Energy=fEnergy;
}
void ParticleHit::SetRawEnergy(float fRawEnergy){
	RawEnergy=fRawEnergy;
}
void ParticleHit::SetTime(float fTime){
	Time=fTime;
}
void ParticleHit::SetRing(int fRing){
	Ring=fRing;
}
void ParticleHit::SetSector(int fSector){
	Sector=fSector;
}
void ParticleHit::SetRmult(int fRmult){
	Rmult=fRmult;
}
void ParticleHit::SetSmult(int fSmult){
	Smult=fSmult;
}

void ParticleHit::SetPIDlinear(float Value){
	PIDlinear=Value;
}
void ParticleHit::SetAngle(float fAngle){
	Angle=fAngle;
}

void ParticleHit::SetEx(float fEx){
	Ex=fEx;
}
void ParticleHit::SetRecoilAngle(float fRecoilAngle){
	RecoilAngle=fRecoilAngle;
}

//Getters
float ParticleHit::GetEnergy(){
	return Energy;
}
float ParticleHit::GetRawEnergy(){
	return RawEnergy;
}
float ParticleHit::GetTime(){
	return Time;
}
int ParticleHit::GetRing(){
	return Ring;
}
int ParticleHit::GetSector(){
	return Sector;
}
int ParticleHit::GetRmult(){
	return Rmult;
}
int ParticleHit::GetSmult(){
	return Smult;
}

float ParticleHit::GetPIDlinear(){
	return PIDlinear;
}
float ParticleHit::GetAngle(){
	return Angle;
}

float ParticleHit::GetEx(){
	return Ex;
}
float ParticleHit::GetRecoilAngle(){
	return RecoilAngle;
}

//Other functions
void ParticleHit::IncrementRmult(){
	Rmult++;
}
void ParticleHit::IncrementSmult(){
	Smult++;
}
void ParticleHit::ResetAll(){
	Energy=0;
	RawEnergy=0;
	Time=0;
	Ring=-1;
	Sector=-1;
	Rmult=0;
	Smult=0;
	PIDlinear=0;
	Angle=0;

	Ex=0;
	RecoilAngle=0;
}



