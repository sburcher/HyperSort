#include "../include/LeafArray.h"

//Constructor
LeafArray::LeafArray(){ }

//Setters
void LeafArray::SetEnergy(int Index, float fEnergy){
	Energy[Index]=fEnergy;
}
void LeafArray::SetRawEnergy(int Index, float fRawEnergy){
	RawEnergy[Index]=fRawEnergy;
}
void LeafArray::SetTime(int Index, float fTime){
	Time[Index]=fTime;
}
void LeafArray::SetId(int Index, int fId){
	Id[Index]=fId;
}

//Getters
float LeafArray::GetEnergy(int Index){
	return Energy[Index];
}
float LeafArray::GetRawEnergy(int Index){
	return RawEnergy[Index];
}
float LeafArray::GetTime(int Index){
	return Time[Index];
}
int LeafArray::GetId(int Index){
	return Id[Index];
}

//Other functions

void LeafArray::ResetEnergy(){
	int i;
	for(i=0;i<48;i++){
		Energy[i]=0;
		RawEnergy[i]=0;
	}
}
void LeafArray::ResetTime(){
	int i;
	for(i=0;i<48;i++){
		Time[i]=0;
	}
}
void LeafArray::ResetId(){
	int i;
	for(i=0;i<48;i++){
		Id[i]=-1;
	}
}
void LeafArray::ResetAll(){
	this->ResetEnergy();
	this->ResetTime();
	this->ResetId();
}
