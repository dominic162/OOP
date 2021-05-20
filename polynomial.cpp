/*
    Polynomial user defined class;
*/

#include<iostream>
using namespace std;

class Poly{
    private:
        int* arr;
        int capacity;

    public:

        const void print(){
            
            for(int i = capacity-1 ; i >= 1 ; --i){

                if(arr[i] != 0){
                    cout<<"("<<arr[i]<<")x^"<<i<<" + ";
                }

            }

            cout<<arr[0]<<endl;

            return ;
        }

        //set coeff
        void set_coeff(int deg ,int coef){
            if(deg >= capacity){
                int pre_size = capacity;
                while(deg >= capacity){
                    capacity = 2*capacity;
                }

                int* temp = new int[capacity];

                for(int i = 0 ; i < pre_size ; ++i){
                    temp[i] = arr[i];
                }

                for(int i = pre_size ; i < capacity ; ++i){
                    temp[i] = 0;
                }
                delete []arr;
                arr = temp;
            }

            arr[deg] = coef;
            return ;
        }

        //Copy assignment operator
        void operator=(const Poly &obj){
            this->capacity = obj.capacity;
            delete []arr;

            this->arr = new int[capacity];
            for(int i = 0 ; i < capacity ; ++i){
                this->arr[i] = obj.arr[i];
            }

        }

        // + operator overloaded
        Poly operator+(const Poly &obj){
            Poly ans;
            
            int i = 0 , r;

            r = max(this->capacity , obj.capacity);

            ans.set_coeff(r-1 , 0);


            while( i < this->capacity && i < obj.capacity){
                r = this->arr[i] + obj.arr[i];
                ans.set_coeff(i,r);
                ++i;
            }

            while( i < this->capacity){
                ans.set_coeff(i , this->arr[i]);
                ++i;
            }

            while( i < ans.capacity){
                ans.set_coeff(i , obj.arr[i]);
                ++i;
            }

            return ans;

        }

        // - operator oveloaded
        Poly operator-(const Poly &obj){
            Poly ans;
            
            int i = 0 , r;

            r = max(this->capacity , obj.capacity);

            ans.set_coeff(r-1 , 0);


            while( i < this->capacity && i < obj.capacity){
                r = this->arr[i] - obj.arr[i];
                ans.set_coeff(i,r);
                ++i;
            }

            while( i < this->capacity){
                ans.set_coeff(i , this->arr[i]);
                ++i;
            }

            while( i < ans.capacity){
                ans.set_coeff(i , -1*obj.arr[i]);
                ++i;
            }

            return ans;

        }

        //Copy constructor
        Poly(const Poly &obj){
            this->capacity = obj.capacity;
            this->arr = new int[capacity];
            
            for(int i = 0 ; i < capacity ; ++i){
                arr[i] = obj.arr[i];
            }
        }

        //Default constructor
        Poly(){
            arr = new int[1];
            capacity = 1;
            arr[0] = 0;
        }

};

int main(){

    Poly p1;
    p1.set_coeff(4,9);
    p1.set_coeff(3,3);
    p1.set_coeff(0,1);

    Poly p2 = p1;
    p2.print();

    Poly p3;

    p3 = p2;

    p3.print();

    Poly p4;
    p4.set_coeff(5,6);
    p4.set_coeff(2,8);
    p4.set_coeff(1,2);

    p4.print();

    p3 = p1 + p4;
    p3.print();

    p3 = p4 - p1 + p1;

    p3.print();

    return 0;
}