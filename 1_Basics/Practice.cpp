#include<iostream>
using namespace std;

int main(){
    for(int i=0;i<3;i++){
        cout<<endl<<"Outer loop "<<i<<endl;
        for(int j=0;j<3;j++){
            cout<<"Inner Loop "<<j<<endl;
        }
    }
}