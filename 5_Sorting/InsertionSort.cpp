#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> v){
    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

void InsertionSort(vector<int> &v){  // Pass vector by reference to avoid copying
    int n = v.size();
    for(int i = 1; i<n; i++){
        int key = v[i];
        int j = i-1;
        while(j>=0 && v[j]>key){
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = key;
    }
}

int main(){
    vector<int> v;
    v.push_back(44);
    v.push_back(33);
    v.push_back(55);
    v.push_back(22);
    v.push_back(11);
    InsertionSort(v);
    print(v);
    return 0;
}