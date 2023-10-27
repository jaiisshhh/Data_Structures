#include<iostream>
using namespace std;

int main(){
    cout<<("1 -> add");
    
    float a;
    cout<<"Enter a Number: ";
    cin>>a;

    float b;
    cout<<"Enter another Number: ";
    cin>>b;

    char op;
    cout<<"Enter an Operator: ";
    cin>>op;

    switch (op)
    {
    case '+' :
        cout<<a+b<<endl;
        break;
    case '-' :
        cout<<a-b<<endl;
        break;
    case '*' :
        cout<<a*b<<endl;
        break;
    case '/' :
        cout<<a/b<<endl;
        break;
    
    default: cout<<"Enter differnt operator";
        break;
    }
    
    return 0;
    
}