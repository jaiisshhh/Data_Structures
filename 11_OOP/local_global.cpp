#include<iostream>
using namespace std;

int x = 10; // Global Variable
// You can access the global variable anywhere inside the program 

void fun(){
    int x = 1234;
    cout << x << endl;
    ::x = 40;
    cout << "Printing gloabal x " << ::x << endl;
}

int main(){

    x = 20; // Editing global variable or ::x = 20 
    int x = 25; // Local to main() fn.
    cout << x << endl; // Accessing global variable
    // If you have a local variable then that will be printed ! not the global variable
    cout << ::x << endl; // Accessing global variable with :: 

    { // Creating a scope
        int x = 50; // x varibale scoped to this perticular scope 
        cout << x << endl;
    }
    fun();

    return 0;
}