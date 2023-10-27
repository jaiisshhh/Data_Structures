#include<iostream>
using namespace std;

int main(){

    //Example-1
    int age;
    cin>>age;

    if(age>=18){
        cout<<"Eligible for Licience"<<endl;
    }
    else{
        cout<<"Not Eligible for Licience"<<endl;
    }

    //Example-2
    int sides;
    cin>>sides;

    if(sides==3){
        cout<<"Triangle"<<endl;
    }
    else if(sides==4){
        cout<<"Quadilatral"<<endl;
    }
    else if(sides==5){
        cout<<"Pentagone"<<endl;
    }
    else{
        cout<<"Mujhe nai pta"<<endl;
    }
    
    //Example-3
    int num;
    cin>>num;

    if(num>0){
        cout<<"Positive"<<endl;
    }
    else if(num<0){
        cout<<"Negative"<<endl;
    }
    else{
        cout<<"number is zero"<<endl;
    }

    //Example-4
    int num1 = 7;

    if(num1%2==0){
        cout<<"Number is Even"<<endl;
    }
    else{
        cout<<"Number is odd"<<endl;
    }
    return 0;
}