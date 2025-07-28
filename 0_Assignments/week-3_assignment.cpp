#include<iostream>
#include<vector>
using namespace std;

void keyPair(int arr[], int n, int x){
    int low = arr[0]; int high = arr[n-1];
    while(low < high){
        int sum = arr[low] + arr[high];
        if(sum == x){
            cout << "Present" << endl;
        }
        else if(sum < x){
            high--;
        }
        else if(sum > x){
            low++;
        }
        else{
            cout << "not present" << endl;
        }
    }
}

void findMissing(int arr[], int n){
//    for(int i=0; i<n; i++){
//     int index = abs(arr[i]);
//     if(arr[index-1] > 0){
//         arr[index - 1] *= -1;
//     }
//    }
//    for(int i=0; i<n; i++){
//     if(arr[i] > 0){
//         cout << i+1 << " ";
//     }
//    }

    //Swaping and Sorting method
    int i=0; 
    while(i<n){
        int index = arr[i] - 1;
        if(arr[i] != arr[index]){
            swap(arr[i], arr[index]);
        }
        else{
            i++;
        }
    }
    // for(int i=0; i<n; i++){
    //     cout << arr[i] << " ";
    // }
    // cout << endl;
    for(int i=0; i<n; i++){
        if(arr[i] != i+1){
            cout << i+1 << " ";
        }
    }
    cout << endl;
}

void wavePrintMatrix(vector<vector<int>>v){
    int row = v.size();
    int col = v[0].size();
    for(int startCol = 0; startCol < col; startCol++){
        //even no of col -> Top to bottom
        if((startCol & 1)==0){
            for(int i=0; i<row; i++){
                cout << v[i][startCol] << " ";
            }
        }
        else{
        //odd no of col -> bottom to top 
            for(int i=row-1; i>=0; i--){
                cout << v[i][startCol] << " ";
            }
        }
    }
}

int main(){

    // // KEY PAIR / TWO SUM
    // int arr[] = {1, 4, 45, 6, 10, 8};
    // int size = sizeof(arr) / sizeof(int);
    // cout << size;
    // // int n = 6; int x = 16;
    // // keyPair(arr,n,x);

    // MISSING ELEMENTS FORM AN ARRAY WITH DUPLICATES
    // int n; 
    // int arr[] = {1,3,5,3,4};
    // n = sizeof(arr)/sizeof(int);
    // findMissing(arr,n);

    // PRINTING A WAVE MATRIX
    vector<vector<int>> v {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16},
        {17,18,19,20}
    };
    wavePrintMatrix(v);
 
    

    return 0;
}