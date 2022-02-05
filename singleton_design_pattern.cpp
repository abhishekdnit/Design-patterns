//Thread-safe Singleton design pattern example

#include <bits/stdc++.h>

using namespace std;
mutex m;

class Singleton{

static Singleton* ptr;  //private static pointer used to point the Singleton object
Singleton(){};            //Private constructor so that object cannot get created outside of the class
Singleton(const Singleton& obj); // disallow copy constructor
Singleton& operator=(const Singleton& obj); //disallow assignment operator

public:

static Singleton* getobj()
{
    if(ptr==NULL)
    {
        m.lock();
        ptr = new Singleton();
        m.unlock();
    }
    return ptr;
}

};

Singleton *Singleton::ptr = NULL;

int main() 
{

Singleton *obj = Singleton::getobj();
cout<<obj<<endl;
Singleton *obj1 = Singleton::getobj();
cout<<obj1;
return 0;

}