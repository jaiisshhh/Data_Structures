#include<iostream>
using namespace std;

void numsum(int n){
    int ans = 0;
    for(int i=1; i<=n; i++){
        ans = ans + i;
    }
    cout<<ans<<endl;  
}

int main(){
    numsum(5);
    return 0;
}