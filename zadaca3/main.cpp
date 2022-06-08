#include "Vessel.h"
#include <iostream>
using namespace std;

int main(){
    FederationVessel Enterprise;
    RomulanVessel Warbird;
    RomulanVessel Warbird2;

    cout << FederationVessel::NoAllies << endl << RomulanVessel::NoAllies << endl;
    
    
    for (int i = 0; i < 10; ++i ) Enterprise.Charge();
    for (int i = 0; i < 5; ++i ) Warbird.Charge();
    /*
    cout << "Enterprise snage: " << Enterprise.LaserPower << 
            ", " << Enterprise.PhotonPower << endl;
    cout << "Warbird snage: " << Warbird.LaserPower << 
            ", " << Warbird.PlasmaPower << endl;
    */
    Enterprise.FireLaserAt(Warbird);
    //cout << Warbird.Sheilds << ", " << Warbird.Hull << endl;
    //cout << Enterprise.LaserPower << endl;
    Warbird.FireLaserAt(Enterprise);
    //cout << Enterprise.Sheilds << ", " << Enterprise.Hull << endl;
    //cout << Warbird.LaserPower << endl;
    Warbird.Cloak();

    for (int i = 0; i < 10; ++i) Warbird.Charge();
    /*
    cout << "Warbird snage: " << Warbird.LaserPower << 
            ", " << Warbird.PlasmaPower << endl;
    */
    Enterprise.FirePhotonAt(Warbird);
    Warbird.Uncloak();
    Warbird.FirePlasmaAt(Enterprise);

    for (int i = 0; i < 10; ++i) Warbird.Charge();

    Warbird.FirePlasmaAt(Enterprise);
    cout << Warbird.Sheilds << endl << Warbird.Hull << endl;
    cout << Enterprise.Sheilds << endl << Enterprise.Hull << endl;

    return 0;

}