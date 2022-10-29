// CPP program to illustrate
// concept of Virtual Functions
#include<iostream>
using namespace std;

class Animal
{
public:
    Une(int i){ x = i;}
    void MethodeUn() = 0 ;
    void MethodeDeux() = 0 ;
private:
    int x;
};

class Deux
{
public:
    Deux(){}
    void PrintOne(Une u);
};

void Deux::PrintOne(Une u)
{
    std::cout << u.x << std::endl;
}

int main()
{
    Une un(1);
    Deux deux = Deux();
    deux.PrintOne(un);
}

