#include<iostream>
using namespace std;

int main(){

    //IMPLICIT TYPECASTING

    //1. Int --> float
    // int num1 = 10;
    // float num2 = 5.5;
    // float result = num1 + num2; //Implicit conversion of int to float
    // cout<<result<<endl;

    //2. Char --> Int
    // char ch = 'A'; //ASCAI value of A is 65 
    // int a = ch + 1; //65 plus 1 is 66
    // cout<<a<<endl;

    //3. Int --> Char
    // int a = 67;
    // char ch = a;
    // cout<<ch<<endl; //Will print the ASCAI value assigned with 67 which is C
    // cout<<a<<endl; //Will print tha value of a = 67

    //EXPLICIT TYPECASTING
    //Done using a casting operator ()

    //1. Double --> Int
    // double pi = 3.14159265;
    // int intpi = (int)pi; //Explicitly assigned pi as int
    // cout<<intpi<<endl;

    //2. Float --> char
    // float floatingNum = 65.5;
    // char charValue = (char)floatingNum; //Converted float into char and returned the value cussorsponding to the number which is A
    // cout<<charValue<<endl;

    //3. Int --> Float 
    int a = 10;
    int b = 3.0;
    float c = a/((float)b);
    cout<<c<<endl; 

    // Concept 
    // int / int = int
    // int / float = float
    // float / int = float

    
    return 0;
}