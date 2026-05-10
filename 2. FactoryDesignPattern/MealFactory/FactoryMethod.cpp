#include <iostream>
#include <vector>

using namespace std;

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
class BasicWheatBurger : public Burger{
    public:
        void prepare() override{
            cout<<"Preparing basic Wheat burger"<<endl;
        }
};
class StandardWheatBurger : public Burger{
    public:
        void prepare() override{
            cout<<"Preparing standard Wheat burger"<<endl;
        }
};
class PremiumWheatBurger : public Burger{
    public:
        void prepare() override{
            cout<<"Preparing premium Wheat burger"<<endl;
        }
};

//abstract factory and its concreate classes
class BurgerFactory{
    public:
        virtual Burger* createBurger(string& type)=0;
};
class SinghBurger: public BurgerFactory{
    public:
        Burger* createBurger(string& type) override{
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
class KingBurger: public BurgerFactory{
    public:
        Burger* createBurger(string& type) override{
            if(type=="basic")
                return new BasicWheatBurger();
            else if(type=="standard")
                return new StandardWheatBurger();
            else if(type=="premium")
                return new PremiumWheatBurger();
            else{
                cout<<"Invalid Burger Type!"<<endl;
                return NULL;
            }
        }
};

int main()
{
    string type="premium";
    BurgerFactory* myFactory = new KingBurger();
    Burger* burger = myFactory->createBurger(type);
    burger->prepare();
    return 0;
}