#include <iostream>
using namespace std;

struct TrimRes /// Trimester Result
{
    float gpa;
    TrimRes* next;

    TrimRes()
    {
        this->next = NULL;
    }
    TrimRes(float gpa);
};

TrimRes::TrimRes(float gpa)
{
    this->gpa = gpa;
    this->next = NULL;
}


class Student /// Student
{
private:
    int sid;
    string name;
    TrimRes* trim_res;
public:

    Student(int sid)
    {
        this->sid = sid;
        this->trim_res = NULL;
    }
    Student(string name, int sid)
    {
        this->name = name;
        this->sid = sid;
        this->trim_res = NULL;
    }

    void print();
    void add_result(float gpa);
};

void Student::print()
{
    cout << this->name << " " << this->sid << endl;
    if (this->trim_res == NULL) {
        cout << endl;
        return;
    }

    TrimRes* t = this->trim_res;
    float cgpa = 0.0;
    int c = 0;
    while(t != NULL){
        cout << "\t" << t->gpa;
        cgpa += t->gpa;
        c++;
        t = t->next;
    }
    cout << endl;
    cout << "\tCGPA " << cgpa/c << endl;
    cout << endl;
}

void Student::add_result(float gpa)
{
    TrimRes* new_res = new TrimRes(gpa);
    new_res->next = this->trim_res;
    this->trim_res = new_res;
}
