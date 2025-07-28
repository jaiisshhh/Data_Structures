// Maps : Stores key:value pair 
// map : Sorted -> Uses red black trees -> Operations O(logN)
// unordered_map : not Sorted -> uses hashing -> operations O(1)

#include<iostream>
#include<map>
using namespace std;

int main(){

    // Count using hash;
    int n;
    cin >> n;
    int arr[n];
    // for(int i=0; i<n; i++){
    //     cin >> arr[i];
    // }
    // map<int,int> mpp;
    // for(int i=0; i<n; i++){
    //     mpp[arr[i]]++;
    // }
    // CAN ALSO BE TAKEN INSIDE THE LOOP ITLSELF
    
    map<int,int> mpp;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        mpp[arr[i]]++;
    }
    

    int num; cin >> num;
    cout << "It appeared " << mpp[num] << " times" << endl;

    // INTERATING IN MAP 
    for(auto it: mpp){
        cout << it.first << " " << it.second << endl;
    }

    return 0;
} 