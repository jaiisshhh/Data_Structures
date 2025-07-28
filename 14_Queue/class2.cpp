#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void print(queue<int> q){
    cout << "Printing Queue : ";
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

void reverseQueue(queue<int> &q){
    stack<int> st;
    while(!q.empty()){
        st.push(q.front());
        q.pop();
    }
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }
}

void reverseRecursive(queue<int> &q){
    if(q.empty()) return;
    int temp = q.front();
    q.pop();
    reverseRecursive(q);
    q.push(temp);
}

void reverseFirstKelements(queue<int> &q, int k){
    stack<int> st;
    for(int i=0; i<k; i++){
        int temp = q.front();
        q.pop();
        st.push(temp);
    }
    while(!st.empty()){
        int temp = st.top();
        st.pop();
        q.push(temp);
    }
    for(int i=0; i<(q.size()-k); i++){
        int temp = q.front();
        q.pop();
        q.push(temp);
    }
}

void interLeaveQueue(queue<int> &q){
    queue<int> helper;
    //push first half of the queue into the helper queue
    int size = q.size();
    for(int i=0; i<size/2; i++){
        int temp = q.front();
        q.pop();
        helper.push(temp);
    }
    //merging into the main queue
    while(!helper.empty()){
        q.push(helper.front());
        helper.pop();
        q.push(q.front());
        q.pop();
    }
}

void printFirstNeagtiveInteger(int* arr, int n, int k){
    deque<int> dq;
    for(int i=0; i<k; i++){
        if(arr[i] < 0){
            dq.push_back(i);
        }
    }
    for(int i=k; i<n; i++){
        if(dq.empty()) cout << "0" << endl;
        else cout << arr[dq.front()] << " ";
        if(i - dq.front() >= k){
            dq.pop_front();
        }
        if(arr[i] < 0){
            dq.push_back(i);
        }
    }
    if(dq.empty()) cout << "0" << endl;
    else cout << arr[dq.front()] << " ";
}

int main(){
    // REVERSE A QUEUE
    // queue<int> q;
    // for(int i=1; i<=5; i++){
    //     q.push(i);
    // }
    // cout << "Before Reversing" << endl;
    // print(q);
    // //reverseQueue(q);
    // reverseRecursive(q);
    // cout << "After Reversing" << endl;
    // print(q);

    // REVERSE FIRST K ELEMENTS IN A QUEUE
    // queue<int> q;
    // for(int i=1; i<=5; i++){
    //     q.push(i);
    // }
    // int k = 3;
    // reverseFirstKelements(q,k);
    // print(q);

    // INTERLEAVING FIRST & SECOND HALF OF THE QUEUE
    // queue<int> q;
    // q.push(10);
    // q.push(20);
    // q.push(30);
    // q.push(40);
    // q.push(50);
    // q.push(60);
    // interLeaveQueue(q);
    // print(q);

    // FIRST -VE INTEGER IN EVERY WINDOW OF K
    int arr[] = {2,-5,4,-1,-2,0,5};
    int n = 7;
    int k = 3;
    printFirstNeagtiveInteger(arr,n,k);
}