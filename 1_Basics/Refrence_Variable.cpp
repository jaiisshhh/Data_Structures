#include<iostream>
using namespace std;

int main() {
    int n = 5;
    int & k = n;
    int & c = k;

    cout<<"n : "<<n<<endl;
    cout<<"k : "<<k<<endl;
    cout<<"c : "<<c<<endl;

    k++;  // As the value of k is the value of n then increaing k will increase the value of n as well

    
    cout<<"n : "<<n<<endl;
    cout<<"k : "<<k<<endl;
    cout<<"c : "<<c<<endl;

    return 0;
}