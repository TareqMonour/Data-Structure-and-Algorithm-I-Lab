#include <iostream>
#include "student.h"
using namespace std;

int main(){
    Student sabina("sabina", 31);
    sabina.print();

    sabina.add_result(3.34);
    sabina.add_result(3.44);
    sabina.print();

    Student* amit = new Student("amit", 11);
    amit->print();
    amit->add_result(2.5);
    amit->add_result(2.9);
    amit->add_result(2.7);
    amit->print();

}
