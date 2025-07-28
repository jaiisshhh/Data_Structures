#include <iostream> 
#include <stack>
#include <vector> 
using namespace std;

vector<int> nextSmallerElement(int *arr, int size){
    vector<int> v(5);
    stack<int> st; 
    st.push(-1);
    for(int i=size-1; i>=0; i--){
        while(st.top() >= arr[i]){
            st.pop();
        }
        v[i] = st.top();
        st.push(arr[i]);
    }
    return v;
}

vector<int> prevSmallerElement(int arr[], int size){
    vector<int> v;
    stack<int> st;
    st.push(-1);
    for(int i=0; i<size; i++){
        while(st.top() >= arr[i]){
            st.pop();
        }
        v.push_back(st.top());
        st.push(arr[i]);
    }
    return v;
}

int main(){

    // NEXT SMALLEST ELEMENT
    // int arr[5] = {8,4,6,2,3};
    // int size = 5;
    // vector<int> v = nextSmallerElement(arr,size);
    // for(int i=0; i<size; i++){
    //     cout << v[i] << " ";
    // }

    // PREV SMALLER ELEMENR
    int arr[5] = {8,4,6,2,3};
    int size = 5;
    vector<int> v = prevSmallerElement(arr,size);
    for(auto i : v){
        cout << i << " ";
    }
}