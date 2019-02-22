#ifndef LEAFARRAY_H
#define LEAFARRAY_H

class LeafArray {

private:

	float Energy[48];
	float RawEnergy[48];
	float Time[48];
	float Id[48];

public:
	//Constructor
	LeafArray();
	//Setters
	void SetEnergy(int Index, float fEnergy);
	void SetRawEnergy(int Index, float fRawEnergy);
	void SetTime(int Index, float fTime);
	void SetId(int Index, int fId);
	//Getters
	float GetEnergy(int Index);
	float GetRawEnergy(int Index);
	float GetTime(int Index);
	int GetId(int Index);
	//Other
	void ResetEnergy();
	void ResetTime();
	void ResetId();
	void ResetAll();

};

#endif
