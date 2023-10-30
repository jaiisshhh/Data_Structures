#include<iostream>
using namespace std;

int main(){
    
    int arr[5] = {1,2,3,4,5};
    int key = 10;
    bool flag = 0;
    // 0 Not Found
    // 1 FOund
    for(int i=0; i<5; i++){
        if(arr[i]==key){
            flag = 1;
            break;
        }   
    }
    if(flag == 1){
        cout<<"Found"<<endl;
    }
    else{
        cout<<"Not-Found"<<endl;
    }
    
    return 0;
}