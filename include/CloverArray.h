#ifndef CLOVERARRAY_H
#define CLOVERARRAY_H

class CloverArray {

private:

	float Energy[12];
	float DopplerEnergy[12];
	float Time[12];
	int Id[12];
	int Leaf[12];
	int Mult;
	float CosAlpha[12];

public:
	//Constructor
	CloverArray();
	//Setters
	void SetEnergy(int Index, float fEnergy);
	void SetDopplerEnergy(int Index, float fDopplerEnergy);
	void SetTime(int Index, float fTime);
	void SetId(int Index, int fId);
	void SetLeaf(int Index, int fLeaf);
	void SetMult(int fMult);
	void SetCosAlpha(int Index, float fCosAlpha);
	//Getters
	float GetEnergy(int Index);
	float GetDopplerEnergy(int Index);
	float GetTime(int Index);
	int GetId(int Index);
	int GetLeaf(int Index);
	int GetMult();
	float GetCosAlpha(int Index);

	//Other functions
	void IncrementMult();
	void ResetEnergy();
	void ResetTime();
	void ResetId();
	void ResetLeaf();
	void ResetCosAlpha();
	void ResetAll();
		
};

#endif
