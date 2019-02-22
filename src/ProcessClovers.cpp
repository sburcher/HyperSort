#include <cstdlib>
#include "Sort.h"
#include "LeafGains.h"
#include "Declarations.h"
#include "ProcessClovers.h"


bool ProcessClovers(CloverArray &Clover, LeafArray &LeafList){

	int i,j,k;
	float RandomOffset,OldValue;
	float MaxEnergy;

	//Get Leaf events that have both Energy and Time

	for(i=0;i<Leaf.Emult;i++){
		//for(j=0;j<Leaf.Tmult;j++){
			//if(Leaf.Echan[i]==Leaf.Tchan[j]&&Leaf.ReadE[i]>0&&Leaf.ReadT[j]>0){ //Require energy and time in same leaf
			//if(Leaf.ReadE[i]>0){ //Require leaf energy to be non-zero
			if(true){
				RandomOffset = rand()/((float)RAND_MAX+1);
				Leaf.Eid[Leaf.Echan[i]]=Leaf.Echan[i];
				OldValue=(RandomOffset+Leaf.ReadE[i]);
				Leaf.RawE[Leaf.Echan[i]]=Leaf.ReadE[i];
				//Leaf.Energy[Leaf.Echan[i]]=leaf_cal[Leaf.Echan[i]][0]+leaf_cal[Leaf.Echan[i]][1]*OldValue; //Old Calibrations
				//Leaf.Energy[Leaf.Echan[i]]=LeafCalibration[Leaf.Echan[i]][0]+LeafCalibration[Leaf.Echan[i]][1]*OldValue+LeafCalibration[Leaf.Echan[i]][2]*OldValue*OldValue;
				Leaf.Energy[Leaf.Echan[i]]=NewLeafCalibration[Leaf.Echan[i]][0]+NewLeafCalibration[Leaf.Echan[i]][1]*OldValue;
				Leaf.Time[Leaf.Echan[i]]=Leaf.ReadT[i];
				Leaf.Tid[Leaf.Tchan[i]]=Leaf.Tchan[i];

				//LeafList.SetId(Leaf.Echan[i],Leaf.Echan[i]);
				//LeafList.SetEnergy(Leaf.Echan[i],Leaf.Energy[Leaf.Echan[i]]);
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

		if(Leaf.RawE[i]>0){
			LeafList.SetId(i,i);
			LeafList.SetEnergy(i,Leaf.Energy[i]);
			LeafList.SetRawEnergy(i,Leaf.RawE[i]);

		}


		//cout << "i = "<<i<<"\tLeaf.Eid[i] = "<<Leaf.Eid[i]<<"\tLeaf.Energy[i] = "<<Leaf.Energy[i]<<endl;
		//j=(int)Leaf.Eid[i]/4; //Clover number
		j=(int)i/4; //Clover number
		if(BGO.Energy[j]==0 && Leaf.Energy[i]>0){ //Compton Suppression
		//if(Leaf.Energy[i]>0){ //NO Compton Suppression
		//cout << "i = "<<i<<"\tLeaf.Eid[i] = "<<Leaf.Eid[i]<<"\tLeaf.Energy[i] = "<<Leaf.Energy[i]<<endl;
			Clover.SetEnergy(j,Clover.GetEnergy(j)+Leaf.Energy[i]);
			Clover.SetId(j,j);
		}
		//Find Leaf with highest energy (used for first interaction point in doppler correction
		if((i%4)==3 && BGO.Energy[j]==0){ //Last leaf in clover (i= 3,7,11,15,19,23,27,31,35,39,43,47)
		//if((i%4)==3){ //Last leaf in clover (i= 3,7,11,15,19,23,27,31,35,39,43,47)
			MaxEnergy=0.0;
			for(k=3;k>-1;k--){ //k=3,2,1,0 -> Leaf = 0,1,2,3 ; 4,5,6,7
				if(Leaf.Energy[i-k]>MaxEnergy){
					MaxEnergy=Leaf.Energy[i-k];
					Clover.SetLeaf(j,3-k);
					//cout <<"i = "<<i<< " j = "<<j<<" k = "<<k<< " Clover Id = " << Clover.GetId(j) << " Leaf = "<<Clover.GetLeaf(j)<<" Max E = "<<MaxEnergy<<endl;
				}
			}
		}	
	}

	Clover.SetMult(0);
	for(i=0;i<12;i++){ //Count Clover multiplicity for this event
		if(Clover.GetEnergy(i)>0){
			Clover.IncrementMult();
			Clover.SetTime(i,Leaf.Time[(i*4)+Clover.GetLeaf(i)]);
		}
	}

	//return true;
	
	if(Clover.GetMult()>0){
		return true;
	}else{
		return false;
	}
}
