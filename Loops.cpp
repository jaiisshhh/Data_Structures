#include<iostream>
using namespace std;

int main(){

    //FOR LOOP 
    //Print Jaish 5 times
    for(int i=1;i<=5;i++){
        cout<<"Jaish"<<endl;
    }
    //How many times will Hello Print
    for(int i=10;i<=12;i++){
        cout<<"Hello"<<endl;
    }
    //Print Counting from 1 to 10
    for(int i=1;i<=10;i++){
        cout<<i<<endl;
    }
    //What will be the output ?
    for(int i=2;i<=10;i=i+2){
        cout<<i<<endl;
    }
    //Print counting from 10 to 1
    for(int i=10;i>=0;i--){
        cout<<i<<endl;
    }
    //Print 5 A
    for(int i=1;i<=5;i++){
        cout<<'A'<<" ";
    }
    //Inner Outer Loop Example
    for(int i=0;i<3;i++){
        cout<<endl<<"Outer loop "<<i<<endl;
        for(int j=0;j<3;j++){
            cout<<"Inner Loop "<<j<<endl;
        }
    }
    //Print Table of 19
    for(int i=1; i<=10; i++){
        cout<<i*19<<endl;
    }
    //Print all even numbers from 1 to 100
    for(int i=1; i<=100; i++){
        if(i%2==0){
            cout<<i<<endl;
        }
    }
    
    return 0;
}