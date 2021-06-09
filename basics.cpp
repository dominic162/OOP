#include<iostream>
using namespace std;

class Student{
    public:
        int roll_no;

        Student(int r){
            this->roll_no = r;
        }

        Student(Student &s1){
            this->roll_no = s1.roll_no;
        }
};

int main(){

    Student * s1 = new Student(21);

    Student s2(*s1);

    return 0;
}