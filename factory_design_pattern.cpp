// Factory Design Pattern Example
//  Factory class is used to create and return the user input type object on demand.

#include <bits/stdc++.h>

using namespace std;

enum VehicleType{
    Two_wheel,Three_wheel,Four_wheel
};

//Inteface
class Vehicle{
public:
virtual void print()=0; 
};

class two_wheeler:public Vehicle{
public:
void print()
{
    cout<<"Two Wheeler\n";
}
};
class three_wheeler:public Vehicle{
public:
void print()
{
    cout<<"Three Wheeler\n";
}
};
class four_wheeler:public Vehicle{
public:
void print()
{
    cout<<"four Wheeler\n";
}
};

class Factory{
public:
static Vehicle* create(VehicleType t)
{
    if(t==Two_wheel)
        return new two_wheeler();
    else if(t==Three_wheel)
        return new three_wheeler();
    else if(t==Four_wheel)
        return new four_wheeler();
    else 
        return NULL;
}
};
int main() 
{
VehicleType type;
type=Two_wheel;
Vehicle *p = NULL;
 p= Factory::create(type);
p->print();
type=Four_wheel;
p = Factory::create(type);
p->print();
return 0;

}