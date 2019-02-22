#include "gains.h"

bool ProcessClovers(CloverArray &Clover){

	int i,j;
	float RandomOffset,OldValue;

	//Get Leaf events that have both Energy and Time

	for(i=0;i<Leaf.Emult;i++){
		//for(j=0;j<Leaf.Tmult;j++){
			//if(Leaf.Echan[i]==Leaf.Tchan[j]&&Leaf.ReadE[i]>0&&Leaf.ReadT[j]>0){
			if(true){
				RandomOffset = rand()/((float)RAND_MAX+1);
				Leaf.Eid[Leaf.Echan[i]]=Leaf.Echan[i];
				//Leaf.Energy[Leaf.Echan[i]]=leaf_cal[Leaf.Echan[i]][0]+leaf_cal[Leaf.Echan[i]][1]*Leaf.ReadE[i]; //Old Calibrations
				OldValue=(RandomOffset+Leaf.ReadE[i]);
				Leaf.Energy[Leaf.Echan[i]]=LeafCalibration[Leaf.Echan[i]][0]+LeafCalibration[Leaf.Echan[i]][1]*OldValue+LeafCalibration[Leaf.Echan[i]][2]*OldValue*OldValue;
				Leaf.Time[Leaf.Echan[i]]=Leaf.ReadT[i];
				Leaf.Tid[Leaf.Tchan[i]]=Leaf.Tchan[i];
			}
		//}
	}


	//Get BGO events that have both Energy and Time
	for(i=0;i<BGO.Emult;i++){
		//for(j=0;j<BGO.Tmult;j++){
			//if(BGO.Echan[i]==BGO.Tchan[j]&&BGO.ReadE[i]>0&&BGO.ReadT[j]>0){
				BGO.Eid[BGO.Echan[i]]=BGO.Echan[i];
				BGO.Energy[BGO.Echan[i]]=BGO.ReadE[i];
				BGO.Tid[BGO.Echan[i]]=BGO.Tchan[i];
				BGO.Time[BGO.Echan[i]]=BGO.ReadT[i];
			//}	
		//}
	}

	//Addback and Compton suppression
	for(i=0;i<48;i++){
		j=(int)Leaf.Eid[i]/4; //Clover number

		if(BGO.Energy[j]==0 && Leaf.Energy[i]>0){ //Compton Suppression
		//if(Leaf.Energy[i]>0){

			Clover.SetEnergy(j,Clover.GetEnergy(j)+Leaf.Energy[i]);
			Clover.SetId(j,j);
		}	
	}

	Clover.SetMult(0);
	for(i=0;i<12;i++){ //Count Clover multiplicity for this event
		if(Clover.GetEnergy(i)>0){
			Clover.IncrementMult();
		}
	}

	return true;
	
	if(Clover.GetMult()>0){
		return true;
	}else{
		return false;
	}
}
