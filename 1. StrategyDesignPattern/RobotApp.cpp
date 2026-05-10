#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

//strategy interface for walk
class WalkableRobot
{
    public:
        virtual void walk()=0;
        virtual ~WalkableRobot() {}
};

//concrete strategies for walk
class NormalWalk : public WalkableRobot{
    public:
        void walk() override{
            cout<<"walking normally"<<endl;
        }
};
class NoWalk : public WalkableRobot{
    public:
        void walk() override{
            cout<<"Cannot walk"<<endl;
        }
};

//strategy interface for talk
class TalkableRobot{
    public:
        virtual void talk()=0;
        virtual ~TalkableRobot() {}
};

//concreate strategies for talk
class NormalTalk : public TalkableRobot{
    public:
        void talk() override{
            cout<<"Talking normally"<<endl;
        }
};
class NoTalk : public TalkableRobot{
    public:
        void talk() override{
            cout<<"Cannot talk"<<endl;
        }
};

// --- Strategy Interface for Fly ---
class FlyableRobot {
public:
    virtual void fly() = 0;
    virtual ~FlyableRobot() {}
};

class NormalFly : public FlyableRobot {
public:
    void fly() override { 
        cout << "Flying normally..." << endl; 
    }
};

class NoFly : public FlyableRobot {
public:
    void fly() override { 
        cout << "Cannot fly." << endl; 
    }
};

//Robot base class
class Robot{
    protected:
        WalkableRobot* walkBehaviour;
        TalkableRobot* talkBehaviour;
        FlyableRobot* flyBehaviour;
    public:
        //contructor
        Robot(WalkableRobot* w, TalkableRobot* t, FlyableRobot* f)
        {
            this->walkBehaviour=w;
            this->talkBehaviour=t;
            this->flyBehaviour=f;
        }
        void walk()
        {
            walkBehaviour->walk();
        }
        void talk() { 
            talkBehaviour->talk(); 
        }
        void fly() { 
            flyBehaviour->fly(); 
        }

        virtual void projection() = 0; // Abstract method for subclasse
        virtual ~Robot() {}
};

//concrete Robot types
class CompanionRobot : public Robot{
    public:
        CompanionRobot(WalkableRobot* w, TalkableRobot* t, FlyableRobot* f)
            : Robot(w, t, f){}

        void projection() override{
            cout<<"Displaying friendly companion features"<<endl;
        }
};
class WorkerRobot : public Robot {
public:
    WorkerRobot(WalkableRobot* w, TalkableRobot* t, FlyableRobot* f)
        : Robot(w, t, f) {}

    void projection() override {
        cout << "Displaying worker efficiency stats..." << endl;
    }
};

int main(){
    WalkableRobot* normalwalk = new NormalWalk();
    TalkableRobot* notalk = new NoTalk();
    FlyableRobot* nofly = new NoFly();
    Robot *robo1 = new CompanionRobot(normalwalk, notalk, nofly);
    robo1->walk();
    robo1->talk();
    robo1->fly();
    robo1->projection();

    cout<<"---------------------"<<endl;
    Robot *robot2 = new WorkerRobot(normalwalk, notalk, nofly);
    robot2->walk();
    robot2->talk();
    robot2->fly();
    robot2->projection();

    delete robo1;
    delete robot2;
    delete normalwalk;
    delete notalk;
    delete nofly;
    return 0;
}