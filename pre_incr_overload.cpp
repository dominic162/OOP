#include<iostream>
using namespace std;

class Fraction{

    private:
        int num,denom;

    public:

        //pre increment: return by reference
        Fraction& operator++(){
            num += denom ;
            return *this;
        }

        //post increment
        Fraction operator++(int){
            num += denom ;
            return *this;
        }


        void print(){
            cout<< this->num <<" "<<this->denom<<endl;
        }
        
        Fraction(int n , int d):num(n),denom(d){
        }

};

int main(){

    Fraction f1(7,3);
    Fraction f2(8,3);

    Fraction f3 = ++(++f2);

    f2.print();
    f3.print();

    return 0;
}