#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

// void printArray(int arr[][3], int row, int col){
//     for(int i=0; i<row; i++){
//         for(int j=0; j<col; j++){
//             cout << arr[i][j] << " ";
//         }
//         cout<<endl;
//     }
// }
// void printColArray(int arr[][3],int row,int col){
//     for(int i=0;i<col;i++){
//         for(int j=0;j<row;j++){
//             cout << arr[j][i]<<" ";
//         }
//         cout<<endl;
//     }
// }

// bool findTarget(int arr[][3],int row,int col, int target){
//     bool answer = 0;
//     for(int i=0; i<row; i++){
//         for(int j=0; j<col; j++){
//             if(arr[i][j]==target){
//                 answer = 1;
//                 break;   
//             }
//         }
//     }
//     if(answer == 1){
//         cout << "The target is found" << endl;
//     }
//     else{
//         cout << "The target was not found" << endl;
//     }
    
// }

// int findMax(int arr[][3], int row, int col){
//     int maxAns = INT_MIN;
//     for(int i=0; i<row; i++){
//         for(int j=0; j<col; j++){
//             if(arr[i][j] > maxAns){
//                 maxAns = arr[i][j];
//             }
//         }
//     }
//     return maxAns;
// }

void rowWiseSum(int arr[][4],int row, int col){
    for(int i=0; i<col; i++){
        int sum = 0;
        for(int j=0; j<row; j++){
            sum += arr[i][j];
            
        }
        cout << sum << endl;
    }
}

int main(){

    // int arr[4][3] = {
    //     {1,2,3},
    //     {4,5,6},
    //     {7,8,9},
    //     {10,11,12}
    // };
    // int row = 4;
    // int col = 3;
    // //Row wise printing
    // // printArray(arr,row,col);
    // //Col wise printing 
    // printColArray(arr,row,col);

    // int arr[3][3];
    // for(int i=0; i<3; i++){
    //     for(int j=0; j<3; j++){
    //         cin >> arr[i][j];
    //     }
    // }
    // printArray(arr,3,3);
    // cout << endl;
    // int target = 10;
    // findTarget(arr,3,3,target);
    // cout << endl;

    // int arr[3][3] = {
    //     {1,2,3},
    //     {4,5,6},
    //     {7,8,9}
    // };
    // findMax(arr,3,3); 

    //ROW WISE SUM
    // int arr[3][4] = {
    //     {1,2,3,4},
    //     {4,24,33,55},
    //     {1,4,87,218},
    // };
    // rowWiseSum(arr,3,4);

    //2D-VECTOR
    // vector< vector<int> > arr(5,vector<int>(10,0));
    // for(int i=0; i<arr.size(); i++){
    //     for(int j=0; j<arr[i].size(); j++){
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    //JACKED ARRAY : have different number of columns in each row
    vector< vector<int> > brr;
    vector<int> vec1(5,0);
    vector<int> vec2(6,1);
    vector<int> vec3(7,0);
    vector<int> vec4(4,-1);
    vector<int> vec5(9,0);    
    
    brr.push_back(vec1);
    brr.push_back(vec2);
    brr.push_back(vec3);
    brr.push_back(vec4);
    brr.push_back(vec5);

    for(int i=0; i<brr.size(); i++){
        for(int j=0; j<brr[i].size();j++){
            cout << brr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}