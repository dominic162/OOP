#include<iostream>
using namespace std;

class Vehicle{ // Abstract class
    protected:
        int a;
    public:
        virtual void print() = 0; // Pure virtual fn
};

class Car:public Vehicle{
    public:

        void set(int x){
            a = x;
        }

        int get(){
            return a;
        }

        void print(){
            cout<<"Car";
        }

};

int main(){

    Vehicle* p = new Car;

    p->print();

    return 0;
}