#include<iostream>
using namespace std;


class complex{

    private:
        int real , imag;
    
    public:

        void add( const complex &c2 ){

            this->real = this->real + c2.real ;
            this->imag = this->imag + c2.imag ;

        }

        void multiply( const complex &c2 ){

            this->real = (this->real * c2.real) - (this->imag * c2.imag) ;
            this->imag = (this->real * c2.imag) + (c2.real * this->imag) ;

        }

        void display(){

            cout<<"Real part: "<< this->real <<"\nImaginary part: "<< this->imag<<endl;
        
        }

        complex(int real , int imag){
            this->real = real;
            this->imag = imag;
        }

};


int main(){

    complex c1(2,3);
    complex c2(4,5);

    c1.display();
    c2.display();
    
    c1.add(c2);
    c1.display();

    c1.multiply(c2);
    c1.display();

    return 0;
}