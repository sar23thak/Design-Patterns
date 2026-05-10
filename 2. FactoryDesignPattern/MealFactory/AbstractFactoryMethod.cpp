#include <iostream>
#include <vector>

using namespace std;

//product 1 burger
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

//product2  garlic bread
class GarlicBread{
    public:
        virtual void prepare()=0;
};

class BasicGarlicBread : public GarlicBread{
    public:
        void prepare() override{
            cout<<"preparing basic garlic bread"<<endl;
        }
};
class CheeseGarlicBread : public GarlicBread{
    public:
        void prepare() override{
            cout<<"preparing cheese garlic bread"<<endl;
        }
};
class BasicWheatGarlicBread : public GarlicBread{
    public:
        void prepare() override{
            cout<<"preparing basic wheat garlic bread"<<endl;
        }
};
class CheeseWheatGarlicBread : public GarlicBread{
    public:
        void prepare() override{
            cout<<"preparing cheese wheat garlic bread"<<endl;
        }
};

//abstract factory
class MealFactory{
    public:
        virtual Burger* createBurger(string& type)=0;
        virtual GarlicBread* createGarlicBread(string& type)=0;
};
//concreate classes for factory
class SinghMeals : public MealFactory{
    public:
        Burger* createBurger(string& type) override
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
        GarlicBread* createGarlicBread(string& type) override{
            if(type=="basic")
                return new BasicGarlicBread();
            else if(type=="cheese")
                return new CheeseGarlicBread();
            else{
                cout<<"Invalid Garlic Bread Type!"<<endl;
                return NULL;
            }
        }
};
class KingMeals : public MealFactory{
    public:
        Burger* createBurger(string& type) override
        {
            if(type=="basic")
                return new BasicWheatBurger();
            else if(type=="standard")
                return new StandardWheatBurger();
            else if(type=="premium")
                return new PremiumWheatBurger();
            else{
                cout<<"Invalid Wheat Burger Type!"<<endl;
                return NULL;
            }
        }
        GarlicBread* createGarlicBread(string& type) override{
            if(type=="basic")
                return new BasicWheatGarlicBread();
            else if(type=="cheese")
                return new CheeseWheatGarlicBread();
            else{
                cout<<"Invalid Wheat Garlic Bread Type!"<<endl;
                return NULL;
            }
        }
};
int main(){
    string BurgerType="standard";
    string GarlicBreadType="cheese";

    MealFactory* myfactory = new KingMeals();
    Burger* burger = myfactory->createBurger(BurgerType);
    GarlicBread* garlicBread = myfactory->createGarlicBread(GarlicBreadType);

    burger->prepare();
    garlicBread->prepare();
    return 0;
}