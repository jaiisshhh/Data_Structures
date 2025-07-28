#include<iostream>
using namespace std;

bool isPrime(int n){
    for(int i=2; i<=n-1; i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

int main(){
    
    bool prime = isPrime(12);
    if(prime){
        cout<<"Prime number"<<endl;
    }
    else{
        cout<<"Not a prime number"<<endl;
    }
    return 0;

}