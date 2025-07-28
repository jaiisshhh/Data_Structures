#include<iostream>
using namespace std;

int main(){

    // int arr[10];
    // cout << "Address of arr is " << &arr << endl;  // You can use an operator '&a' to know the address of the operator 
    // cout << "Size of arr is " << sizeof(arr) << endl;  // You can use 'sizeof()' to get the size 

    // int arr2[5] = {1,2,3,4,5};
    // int n = 5;
    // for(int i = 0; i < n; i++){  // Printing the values in an array using loop 
    //     cout<<arr2[i]<<" ";
    // }
    // cout<<endl;

    // int arr3[5];
    // int n = 5;
    // cout<<"Put the value of the input number : "<<endl;
    // for(int i = 0; i < n; i++){  // Taking the input in an array
    //     cin >> arr3[i];
    // }
    // cout<<endl;
    // for(int i=0; i<n; i++){
    //     cout<<arr3[i]<<" ";
    // }
    // cout<<endl;

    //TAKE AN INPUT FOR THE ARRAY AND OUTPUT THE DOUBLE OF THE ARRAY ELEMENTS
    // int arr[10];
    // int n = 10;
    // cout << "Enter the values :" ;
    // for(int i = 0; i<n; i++){
    //     cin >> arr[i];
    // }
    // cout<<endl;
    // for(int i = 0; i<n; i++){
    //     cout << 2*arr[i] << " ";
    // }
    // cout<<endl;

    //SUM OF ELEMENTS OF THE ARRAY
    // int arr[5];
    // int n = 5;
    // for(int i=0; i<n; i++){
    //     cin>>arr[i];
    // }
    // int sum = 0;
    // for(int i=0; i<n; i++){
    //     sum = sum + arr[i];
    // }
    // cout << "Total sum of elements of array is : " << sum <<endl;

    // int arr[] = {1,2,3,4};
    // int n = 4;
    // for(int i=0; i<n; i++){
    //     for(int j=i; j<n; j++){
    //         cout << arr[i] << " , " << arr[j] <<endl;
    //     }
    // }
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++){
    //         for(int k=0; k<n; k++){
    //             cout<<arr[i]<<","<<arr[j]<<","<<arr[k]<<endl;
    //         }
    //     }
    // }
    int n = 5;
    int arr[5] = {1,2,3,4,5};
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            for(int k=j; k<=j; k++){
                cout << arr[k] << " ";
            }
        }
    }
    return 0;
}