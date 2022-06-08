using namespace std;

class Vessel{
public:
    int Sheilds;
    int Hull;
    bool Cloaked;
    int LaserPower;

    Vessel();
    virtual ~Vessel();
    virtual void Charge() = 0;
    void FireLaserAt(Vessel& Target);

};

class FederationVessel:public Vessel{
public:
    int PhotonPower;
    static int NoAllies;

    FederationVessel();
    void FirePhotonAt(Vessel& Target);
    void Charge();
    ~FederationVessel();
};

class RomulanVessel:public Vessel{
public:
    int PlasmaPower;
    static int NoAllies;

    RomulanVessel();
    void FirePlasmaAt(Vessel& Target);
    void Charge();
    void Cloak();
    void Uncloak();
    ~RomulanVessel();
};