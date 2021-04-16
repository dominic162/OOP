#include<iostream>
using namespace std;

class complex{
    public:
        int real,imag;

        complex operator + (const complex &obj){
            complex ref;
            ref.real = real + obj.real;
            ref.imag = imag + obj.imag;
            return ref;
        }

        complex(int r=0,int i=0):real(r),imag(i){}
};


int main(){

    complex c1(5,10),c2(4,6);
    complex c3=c1+c2;

    cout<<"Real part of c3 is "<<c3.real<<" \n imaginary part is "<<c3.imag;

    return 0;
}