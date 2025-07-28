#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Student{
    // Properties
    // Attributes / State
public:
    int id; 
    int age;
    bool present;
    string name;
    int nos;

    // Constructor : Default 
    Student(){
        cout << "Student ctor called" << endl;
    }
    // Constructor : Parameterized
    Student(int _id, int _age, bool _present, string _name, int _nos, string _gf){
        id = _id;
        age = _age;
        present = _present;
        name = _name;
        nos = _nos;
        gf = _gf;
        cout << "Student parameterized ctor called" << endl;
    }

private:
    string gf;
public:
    // Behaviour
    // Methods / fn.
    void study(){
        cout << "Studying" << endl;
    };
    void sleep(){
        cout << "Sleeping" << endl;
    };
    void bunk(){
        cout << "Bunking" << endl;
    };
private:
    void chatting(){
        cout << "Chatting" << endl;
    };
};

int main(){

    //cout << sizeof(Student) << endl;

    // Object -> Instance of a class
    // Student s1;
    // s1.name = "Jaish";
    // s1.age = 20;
    // s1.id = 1;
    // s1.nos = 5;
    // s1.present = 1;
    // Student s2;

    Student s1; // Will call default constructor
    Student s2(2,20,1,"Snehashree",5,"Jaish"); // Will call Parametorized ctor
    cout << s2.name << endl;
    cout << s2.id << endl;

    return 0;
}