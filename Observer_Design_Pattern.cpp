// Observer Design pattern Example to update price of product and notify to all the subscribed shops about updated price
// Observer design pattern is a one to many dependency(Relationship) between objects so that if one object changes it's state all of
// its dependents are get notified or updated automatically. Ex- New Youtube vedio notifications to subscribers,New mobile update notification 

#include <bits/stdc++.h>

using namespace std;

class IObserver{
public:
virtual void showupdate(int price)=0;
};

class shop:public IObserver{
public:
char *name;

shop(char *n):name(n){
    cout<<"Name of shop = "<<n<<endl;
}

void showupdate(int price)
{
    cout<<"New updated price: "<<price<<" for "<<name<<endl;
}

};

class Subject{
public:
vector<shop*> v;
vector<shop*>::iterator it;
void subscribe(shop *s)
{
    v.push_back(s);
    cout<<"Shop "<<s->name<< " subscribed"<<endl;
}

void unsubscribe(shop *s)
{
    if(!v.empty())
    {
        it = find(v.begin(),v.end(),s);
        if(it!=v.end())
        {
            v.erase(it);
            cout<<"Shop "<<s->name<<" unsubscribed"<<endl;
        }
        else
            cout<<"Shop is not present in the list"<<endl;
    }
    else
        cout<<"Shop list is empty"<<endl;
}

void notify(int price)
{
    for(auto it:v)
        it->showupdate(price);
}
};

class Updateprice:public Subject{
public:

void Changeprice(int price)
{
    notify(price);
}
};

int main() 
{
shop s1("shop1");
shop s2("shop2");
shop s3("shop3");

Updateprice sub;
sub.subscribe(&s1);
sub.subscribe(&s2);
sub.subscribe(&s3);
sub.Changeprice(20);
sub.unsubscribe(&s2);
sub.Changeprice(20);
return 0;

}