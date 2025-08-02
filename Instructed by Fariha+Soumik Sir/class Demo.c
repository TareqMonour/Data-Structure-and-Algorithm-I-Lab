#include<iostream>
using namespace std;

class Student{
private:
    string name;
    float cgpa;
public:
    int sid;
    Student(string name, int sid);
//    Student(string name, int sid){
//        this->name = name;
//        this->sid = sid;
//    }
    void print();
};

Student::Student(string name, int sid){
    this->name = name;
    this->sid = sid;
}

void Student::print(){
    cout << this->name << " " << this->sid << endl << endl;
}

int main(){
    Student amit("amit", 1);
    amit.print();

    Student* rani = new Student("rani",2);
    rani->print();
}
