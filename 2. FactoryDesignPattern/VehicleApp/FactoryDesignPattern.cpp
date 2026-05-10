#include <iostream>
#include <vector>

using namespace std;

//problem statement
// Consider a software application that needs to handle the creation of various types of vehicles,
// such as Two Wheelers, Three Wheelers and Four Wheelers. Each type of vehicle has its own specific properties
// and behaviors.

// issues in without factory method
// Tight Coupline: client depends directly on product classes
// Violation of SRP: client handles both product creation and usaage
// Hard to extend: adding a new vehicle requires modifying the client

// solution: define a factory interface -> create specific factories -> revies the client class -> enhance flexibility

//library classes
class Vehicle
{
    public:
        virtual void printVehicle() =0; //abstract method
        virtual ~Vehicle() {}
};

class TwoWheeler : public Vehicle{
    public:
        void printVehicle() override{
            cout<<"This is a two wheeler"<<endl;
        }
};

class FourWheeler : public Vehicle{
    public:
        void printVehicle() override{
            cout<<"This is a four wheeler"<<endl;
        }
};

//factory interface
class VehicleFactory{
    public:
        virtual Vehicle* createVehicle()=0;
        virtual ~VehicleFactory() {}
};

//concrete factory for two and four wheeler
class TwoWheelerFactory : public VehicleFactory{
    public:
        Vehicle* createVehicle() override{
            return new TwoWheeler();
        }
};
class FourWheelerFactory : public VehicleFactory{
    public:
        Vehicle* createVehicle() override{
            return new FourWheeler();
        }
};

class Client
{
    private:
        Vehicle* vehicle;
    public:
        Client(VehicleFactory* factory)
        {
            this->vehicle = factory->createVehicle();
        }
        Vehicle* getVehicle()
        {
            return vehicle;
        }
        ~Client() {}
};

//driver program
int main(){
    VehicleFactory* twoWheelerFac = new TwoWheelerFactory();
    Client twoWheelerClient(twoWheelerFac);
    Vehicle* twoWheeler = twoWheelerClient.getVehicle();
    twoWheeler->printVehicle();
    delete twoWheelerFac;

    VehicleFactory* FourWheelerFac = new FourWheelerFactory();
    Client fourWheelerClient(FourWheelerFac);
    Vehicle* fourwheeler = fourWheelerClient.getVehicle();
    fourwheeler->printVehicle();
    delete fourwheeler;
    return 0;
}