#include <iostream>
using namespace std;

class Person {
    private:
    int age;
    
    public:
    int getAge() {
        return this -> age;
    }

    void setAge(int age){
        this -> age = age;
    }
};

class Student: public Person {
    private:
    int stuID;
    public:
    int getStuID(){
        return this -> stuID;
    }
    void setStuID(int stuID){
        this -> stuID = stuID;
    }
};

int main() {
    Student stu1;
    stu1.setAge(15);
    stu1.setStuID(104);
    cout << "\nStudent's age: " << stu1.getAge() << endl;
    cout << "\nStudent's ID: " << stu1.getStuID() << endl;
    return 0;
}