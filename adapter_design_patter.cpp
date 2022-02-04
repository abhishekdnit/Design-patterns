//Adapter Design Pattern Example-> making indian charger compatible with USA socket
//We use Adapter Class to make one component/interface compatible with other

#include <bits/stdc++.h>

using namespace std;

//Target
class indiansocket{
public:
virtual void indiancharge()=0;

};

//Adaptee
class usasocket{
public:
void usacharge()
{
    cout<<"USA plug is charging";
}
};

//Adapter
class Socketadapter:public indiansocket, public usasocket{
public:
void indiancharge()
{
    usacharge();
}
};

int main() 
{
unique_ptr<indiansocket> socket = make_unique<Socketadapter>();
socket->indiancharge();
return 0;

}