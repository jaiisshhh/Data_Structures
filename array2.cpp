#include<iostream>
using namespace std;

void printArray(int arr[], int size){
    for(int i=0; i<size; i++){
        cout << arr[i] << " ";
    }
    cout<<endl;
}

// Present -> True
// Absent -> False

bool linearSearch(int arr[], int size, int key){
    for(int i=0; i<size; i++){
        if(arr[i]==key){
            return true;
        }  
    }
    return false;
}

int main(){

    int arr[5] = {1,2,3,4,5};
    int size = 5;
    int key = 4;
    printArray(arr,size);  //Printing using function
    cout<<endl;
    bool ans = linearSearch(arr,size,key);

    if(ans==1){
        cout<<"Key found"<<endl;
    }
    else{
        cout<<"Key not found"<<endl;
    }
    return 0;

}