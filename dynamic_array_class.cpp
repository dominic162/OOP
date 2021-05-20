/*
    Dynamic Array user class;
*/

#include<iostream>
using namespace std;

class DynamicArray{
    private:
        int* arr;
        int size,capacity;

    public:

        void push(int x){
            if(size == capacity){

                int* temparr = new int[2*capacity];
                capacity = 2*capacity;

                for(int i = 0 ; i < size ; ++i){
                    temparr[i] = arr[i];
                }

                delete []arr;
                arr = temparr;

            }

            arr[size] = x;
            ++size;
            return ;
        }

        const int get(int i){
            if( i < size){
                return arr[i];
            }
            return -1;
        }
        
        void update(int i , int x){
            if( i < size){
                arr[i] = x;
                return ;
            }
            cout<<"Index out of bound\n";
            return ;
        }

        void pop(){

            if(size != 0){
                --size;
                return ; 
            }
            cout<<"Index out of bound\n";
            return ;
        }

        DynamicArray(){
            this->arr = new int[1] ;
            this->size = 0 ;
            this->capacity = 1;
        }
    
};

int main(){

    DynamicArray da;

    char ch;

    do{
        cout<<"Enter 1 for push\n2 for pop\n3 for update\n4 for getting\n5 for exit\n";

        cin>>ch;
        int i,x;
        switch(ch){

            case '1':
                cout<<"Enter element: ";
                cin>>x;
                da.push(x);
                break;
            
            case '2':
                da.pop();
                break;
            
            case '3':
                cout<<"Enter index and element: ";
                cin>>i>>x;
                da.update(i,x);
                break;
            
            case '4':
                cout<<"Enter index: ";
                cin>>i;
                cout<< da.get(i)<<endl;
                break;

        }

    }while(ch != '5');

    return 0;
}