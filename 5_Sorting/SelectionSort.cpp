#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> v){
    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

void SelectionSort(vector<int> &v){  // Pass vector by reference to avoid copying
    int n = v.size();
    for(int i = 0; i < n - 1; i++){
        int minIndex = i;
        for(int j = i + 1; j < n; j++){
            if(v[j] < v[minIndex]){
                minIndex = j;  // Update minIndex when a smaller element is found
            }
        }
        // Perform the swap only after finding the minimum element for this pass
        swap(v[i], v[minIndex]);
    }
}

int main(){
    vector<int> v;
    v.push_back(44);
    v.push_back(33);
    v.push_back(55);
    v.push_back(22);
    v.push_back(11);
    SelectionSort(v);
    print(v);
    return 0;
}