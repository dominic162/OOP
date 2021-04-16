#include<iostream>
using namespace std;

class A{
    public:
        void print(){
            cout<<"A\n";
        }
};

class B : public A{
    public:
        void print(){
            cout<<"B\n";
        }
};

class C{
    public:
        virtual void print(){
            cout<<"C\n";
        }
};

class D : public C{
    public:
        void print(){
            cout<<"D\n";
        }
};

int main(){
    A* ptr1 = new B();
    C* ptr2 = new D();
    ptr1->print(); // B must be printed but it prints A 
    ptr2->print(); // because of virtual it prints D

    return 0;
}