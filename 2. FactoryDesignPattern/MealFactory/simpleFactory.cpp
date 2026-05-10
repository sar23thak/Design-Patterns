#include <iostream>
#include <vector>

using namespace std;
//product class
class Burger{
    public:
        virtual void prepare()=0;
        virtual ~Burger() {}
};
//product subclass
class BasicBurger : public Burger{
    public:
        void prepare() override{
            cout<<"Preparing basic burger"<<endl;
        }
};
class StandardBurger : public Burger{
    public:
        void prepare() override{
            cout<<"Preparing standard burger"<<endl;
        }
};
class PremiumBurger : public Burger{
    public:
        void prepare() override{
            cout<<"Preparing premium burger"<<endl;
        }
};

class BurgerFactory{
    public:
        Burger* createBurger(string& type)
        {
            if(type=="basic")
                return new BasicBurger();
            else if(type=="standard")
                return new StandardBurger();
            else if(type=="premium")
                return new PremiumBurger();
            else{
                cout<<"Invalid Burger Type!"<<endl;
                return NULL;
            }
        }
};

int main(){
    string type="standard";
    BurgerFactory* myFactory = new BurgerFactory();
    Burger* burger = myFactory->createBurger(type);
    burger->prepare();
    return 0;
}