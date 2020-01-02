#include<iostream>
#include<vector>
#include <memory>
using namespace std;

int main()
{
int SomeArray[10];

int *pLocation6 = &SomeArray[6];
int *pLocation0 = &SomeArray[0];

cout << "plocation6 = " << pLocation6<<endl;
cout << "plocation0 = " << pLocation0<<endl;
cout << "Difference = " << pLocation6 - pLocation0 <<endl;

cout<<endl;

//memory address and values
int SomeArray2[10] = {3,6,9,12,15,18,21,24,27,30};
int *pLocation1 = &SomeArray2[0];

for(int i=0;i<10;i++)
{
cout<<pLocation1<<"="<<*pLocation1<<endl;
pLocation1++;
}

//char
char SomeString[]  = "Hello!";
char *pSomeString = SomeString;
cout << "pSomeString = " << pSomeString <<endl;

char *pLocation3 = &SomeString[3];
char *pLocation5 = &SomeString[0];


cout << "plocation6 = " << pLocation3<<endl;
cout << "plocation0 = " << pLocation5<<endl;
cout << "Difference = " << pLocation3 - pLocation5 <<endl;

//struct
struct sSomeObject
{
    int x =10;
    int y =20;

    sSomeObject()
    {
        x = 25;
        y = 30;
    }

};

//stack Allocaion (Complie Time)
//sSomeObject pSomeObject[10];

//Heap
//point to array of pointer 
//each array of pointer stores the 
sSomeObject **pSomeObject  = new sSomeObject*[10]();

for (int i=0;i<10;i++)
{
    pSomeObject[i] = new sSomeObject();
}

for(int i=0;i<10;i++)
{
    delete pSomeObject[i];
}

delete[]  pSomeObject;

//Polymorphism
struct sSomeBaseObject
{   
    //virtual keyword it tells the compiler that if I am subclass and 
    //any of my children happens to override this method then call child's method
    virtual const char *identifyYourself()
    {
        return "BaseObject";
    }
};

struct sSomeBaseObjectA : public sSomeBaseObject
{
    const char *identifyYourself()
    {
        return "SubObjectA";
    }
};

struct sSomeBaseObjectB : public sSomeBaseObject
{
    const char *identifyYourself()
    {
        return "SubObjectB";
    }
};

//Normally 

sSomeBaseObject ob_base;
sSomeBaseObjectA ob_A;
sSomeBaseObjectB ob_B;

//array of object
sSomeBaseObject object[10];
object[3] = sSomeBaseObjectA();
for (int i=0;i<10;i++)
{
    cout<< object[i].identifyYourself() <<endl;
}

//direcly call
cout<<ob_base.identifyYourself()<<endl;
cout<<ob_A.identifyYourself()<<endl;
cout<<ob_B.identifyYourself()<<endl;

//intelligent call
sSomeBaseObject **pSomeArray = new sSomeBaseObject *[5];
pSomeArray[0] = new sSomeBaseObjectA();
pSomeArray[1] = new sSomeBaseObject();
pSomeArray[2] = new sSomeBaseObjectB();
pSomeArray[3] = new sSomeBaseObjectA();
pSomeArray[4] = new sSomeBaseObjectB();

for (int i=0;i<5;i++)
{
    //as calling by pointers rather than object so ->
    cout<<pSomeArray[i]->identifyYourself()<<endl;
}


for (int i=0;i<5;i++)
{
    //as calling by pointers rather than object so ->
    delete[] pSomeArray[i];
}
delete[] pSomeArray;
 
//same using vector
std::vector <sSomeBaseObject *> vSomeVector;

vSomeVector.push_back(new sSomeBaseObjectA());
vSomeVector.push_back(new sSomeBaseObjectB());
vSomeVector.push_back(new sSomeBaseObject());
vSomeVector.push_back(new sSomeBaseObjectA());
vSomeVector.push_back(new sSomeBaseObjectB());

for(auto &a:vSomeVector) //& to pass by refrence
    cout << a->identifyYourself()<<endl;

for(auto &a:vSomeVector)
    delete a;

vSomeVector.clear();

//shared_pointer - Shared - Multiple accessors to pointers
{ //Scope 1
std::shared_ptr<sSomeObject> spSomeObject1 = make_shared<sSomeObject>();
    { //Scope 2
        std::shared_ptr<sSomeObject> spSomeObject2 = spSomeObject1;
    }
}

//Smart Pointer Unique only ever one accessoe to pointer 
{ //Scope 1
std::unique_ptr<sSomeObject> upSomeObject1 = make_unique<sSomeObject>();
    { //Scope 2
        std::unique_ptr<sSomeObject> spSomeObject2 = std::move(upSomeObject1);
    }
}


return 0;
}



//run:  g++ -std=c++11 pointers.cpp