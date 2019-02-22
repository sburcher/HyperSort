#include "../include/CloverArray.h"

//Constructor
CloverArray::CloverArray(){ }

//Setters
void CloverArray::SetEnergy(int Index, float fEnergy){
	Energy[Index]=fEnergy;
}
void CloverArray::SetDopplerEnergy(int Index, float fDopplerEnergy){
	DopplerEnergy[Index]=fDopplerEnergy;
}
void CloverArray::SetTime(int Index, float fTime){
	Time[Index]=fTime;
}
void CloverArray::SetId(int Index, int fId){
	Id[Index]=fId;
}
void CloverArray::SetLeaf(int Index, int fLeaf){
	Leaf[Index]=fLeaf;
}
void CloverArray::SetMult(int fMult){
	Mult=fMult;
}
void CloverArray::SetCosAlpha(int Index, float fCosAlpha){
	CosAlpha[Index]=fCosAlpha;
}

//Getters
float CloverArray::GetEnergy(int Index){
	return Energy[Index];
}
float CloverArray::GetDopplerEnergy(int Index){
	return DopplerEnergy[Index];
}
float CloverArray::GetTime(int Index){
	return Time[Index];
}
int CloverArray::GetId(int Index){
	return Id[Index];
}
int CloverArray::GetLeaf(int Index){
	return Leaf[Index];
}
int CloverArray::GetMult(){
	return Mult;
}
float CloverArray::GetCosAlpha(int Index){
	return CosAlpha[Index];
}

//Other functions
void CloverArray::IncrementMult(){
	//Mult++;
	this->SetMult(this->GetMult()+1);
}
void CloverArray::ResetEnergy(){
	int i;
	for(i=0;i<12;i++){
		Energy[i]=0;
		DopplerEnergy[i]=0;
	}
}
void CloverArray::ResetTime(){
	int i;
	for(i=0;i<12;i++){
		Time[i]=0;
	}
}
void CloverArray::ResetId(){
	int i;
	for(i=0;i<12;i++){
		Id[i]=-1;
	}
}
void CloverArray::ResetLeaf(){
	int i;
	for(i=0;i<12;i++){
		Leaf[i]=-1;
	}
}
void CloverArray::ResetCosAlpha(){
	int i;
	for(i=0;i<12;i++){
		CosAlpha[i]=-2;
	}
}
void CloverArray::ResetAll(){
	this->ResetEnergy();
	this->ResetTime();
	this->ResetId();
	this->ResetLeaf();
	this->ResetCosAlpha();
	Mult=0;
}

		

