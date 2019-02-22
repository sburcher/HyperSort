#ifndef PARTICLEHIT_H
#define PARTICLEHIT_H

#include "TObject.h"

class ParticleHit {

private:

	float Energy;
	float RawEnergy;
	float Time;
	int Ring;
	int Sector;
	int Rmult;
	int Smult;
	
	float PIDlinear;
	float Angle;

	float Ex;
	float RecoilAngle;

public:
	//Constructor
	ParticleHit();

	//Setters
	void SetEnergy(float fEnergy);
	void SetRawEnergy(float fRawEnergy);
	void SetTime(float fTime);
	void SetRing(int fRing);
	void SetSector(int fSector);
	void SetRmult(int fRmult);
	void SetSmult(int fSmult);
	void SetPIDlinear(float Value);
	void SetAngle(float fAngle);

	void SetEx(float fEx);
	void SetRecoilAngle(float fRecoilAngle);

	//Getters
	float GetEnergy();
	float GetRawEnergy();
	float GetTime();
	int GetRing();
	int GetSector();
	int GetRmult();
	int GetSmult();
	float GetPIDlinear();
	float GetAngle();

	float GetEx();
	float GetRecoilAngle();

	//Other functions
	void IncrementRmult();
	void IncrementSmult();
	void ResetAll();

};

#endif
