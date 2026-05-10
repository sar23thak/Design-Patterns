#include <iostream>
#include <vector>

using namespace std;

//problem statement
// Consider a software application that needs to handle the creation of various types of vehicles, 
// such as Two Wheelers, Three Wheelers and Four Wheelers. Each type of vehicle has its own specific properties
// and behaviors.

class Vehicle
{
    public:
        virtual void printVehicle() = 0;
};
class TwoWheeler : public Vehicle
{
    public:
        void printVehicle() override{
            cout<<"This is a two wheeler"<<endl;
        }
};
class FourWheeler : public Vehicle
{
    public:
        void printVehicle() override{
            cout<<"This is a 4 wheeler"<<endl;
        }
};

//client or user class
class Client
{
    private:
        Vehicle* vehicle;
    public:
        Client(int type)
        {
            if(type==1)
            {
                vehicle = new TwoWheeler();
            }
            else if(type==2)
            {
                vehicle = new FourWheeler();
            }
            else{
                vehicle=NULL;
            }
        }
        void cleanup()
        {
            if(vehicle != NULL)
            {
                delete vehicle;
                vehicle = NULL;
            }
        }
        Vehicle* getVehicle()
        {
            return vehicle;
        }
};

int main()
{
    Client client(1);
    Vehicle* v = client.getVehicle();
    if(v!=NULL)
        v->printVehicle();
    client.cleanup();
    return 0;
};