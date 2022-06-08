#include "Vessel.h"
#include <iostream>
using namespace std;

// BAZNA KLASA
Vessel::Vessel(){ 
    Sheilds = 100; Hull = 100; 
    LaserPower = 0; Cloaked = false;}
Vessel::~Vessel(){}
void Vessel::FireLaserAt(Vessel& Target){
    if(Cloaked == false){ // pucač nije skriven
        if(Target.Cloaked == false){ // meta nije skrivena
            Target.Sheilds -= LaserPower;
            if(Target.Sheilds < 0){ 
                Target.Hull += Target.Sheilds;
                if(Target.Hull < 0) Target.Hull = 0;
                Target.Sheilds = 0;
            } 
        }
        this->LaserPower = 0;
    }
}

// IZVEDENA KLASA 1
int FederationVessel::NoAllies = 0;
FederationVessel::FederationVessel(){
    PhotonPower = 0; FederationVessel::NoAllies ++;
}
void FederationVessel::FirePhotonAt(Vessel& Target){
    if( PhotonPower >= 5 && Cloaked == false){ // pucač nije skriven i fotonska snaga je veca od 5
        if(Target.Cloaked == false){ // meta nije skrivena
            Target.Sheilds -= 2*PhotonPower;
            if(Target.Sheilds < 0){ 
                Target.Hull += Target.Sheilds;
                if(Target.Hull < 0) Target.Hull = 0;
                Target.Sheilds = 0;
            } 
        }
        this->PhotonPower = 0; // neovisno o skrivenosti mete
    }
}
void FederationVessel::Charge(){
    if(this->Cloaked == false){
        LaserPower ++; PhotonPower ++;
    }
}
FederationVessel::~FederationVessel(){
    FederationVessel::NoAllies --;
}

// IZVEDENA KLASA 2
int RomulanVessel::NoAllies = 0;
RomulanVessel::RomulanVessel(){
    PlasmaPower = 0; RomulanVessel::NoAllies ++;
}
void RomulanVessel::FirePlasmaAt(Vessel& Target){
    if( PlasmaPower >= 10 && Cloaked == false){ // pucač nije skriven i fotonska snaga je veca od 5
        if(Target.Cloaked == false){ // meta nije skrivena
            Target.Sheilds -= 4*PlasmaPower;
            if(Target.Sheilds < 0){ 
                Target.Hull += Target.Sheilds;
                if(Target.Hull < 0) Target.Hull = 0;
                Target.Sheilds = 0;
            } 
        }
        this->PlasmaPower = 0; // neovisno o skrivenosti mete
    }
}
void RomulanVessel::Charge(){
    if(this->Cloaked == false){
        LaserPower ++; PlasmaPower ++;
    }
}
void RomulanVessel::Cloak(){ this->Cloaked = true; }
void RomulanVessel::Uncloak(){ this->Cloaked = false; }
RomulanVessel::~RomulanVessel(){
    RomulanVessel::NoAllies --;
}



