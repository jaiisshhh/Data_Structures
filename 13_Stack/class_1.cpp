#include <iostream>
#include <stack>
using namespace std;

void solveMidElem(stack<int> &st, int &pos, int &ans){
    if(pos == 1){
        ans = st.top();
        return;
    }
    pos--;
    int temp = st.top();
    st.pop();
    solveMidElem(st,pos,ans);
    st.push(temp);
}

int getMidElem(stack<int> &st){
    int size = st.size();
    int pos = 0;
    if(st.empty()){
        return -1;
    }
    else{
        if(size & 1){
            pos = size / 2 + 1;
        }
        else{
            pos = size / 2;
        }
    }
    int ans = -1;
    solveMidElem(st, pos, ans);
    return ans;
}

void insertAtBottom(stack<int> &st, int elem){
    if(st.empty()){
        st.push(elem);
        return;
    }
    int temp = st.top();
    st.pop();
    insertAtBottom(st,elem);
    st.push(temp);
}

void print(stack<int> st){
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

void reverseStack(stack<int> &st){
    if(st.empty()){
        return;
    }
    int temp = st.top();
    st.pop();
    reverseStack(st);
    insertAtBottom(st,temp);
}

void insertIntoSortedStack(stack<int> &st, int elem){
    if(st.empty() || elem > st.top()){
        st.push(elem);
        return;
    }
    int temp = st.top();
    st.pop();
    insertIntoSortedStack(st,elem);
    st.push(temp);
}

void sortStack(stack<int> &st){
    if(st.empty()) return;
    int temp = st.top();
    st.pop();
    sortStack(st);
    insertIntoSortedStack(st,temp);
}

int main(){

    // stack<int> st;
    // st.push(10);
    // st.push(20);
    // st.push(30);
    // cout << st.size() << endl;
    // st.pop();
    // cout << st.size() << endl;
    // cout << st.empty() << endl;
    // cout << st.top() << endl;

    // REVERSE A STRING 
    // string str = "Sanskar";
    // stack<char> st;
    // for(int i=0; i<str.length(); i++){
    //     char ch = str[i];
    //     st.push(ch);
    // }
    // while(!st.empty()){
    //     cout << st.top() << " ";
    //     st.pop();
    // }

    // // FIND MIDDLE ELEMENT OF A STACK 
    // stack<int> st;
    // st.push(10);
    // st.push(20);
    // st.push(30);
    // st.push(40);
    // st.push(50);
    // st.push(60);
    // int mid = getMidElem(st);
    // cout << "Middle element : " << mid << endl;

    // INSERT AT THE BOTTOM OF THE STACK 
    // stack<int> st;
    // st.push(10);
    // st.push(20);
    // st.push(30);
    // st.push(40);
    // st.push(50);
    // int elem = 5;
    // int size = st.size();
    // insertAtBottom(st,elem);
    // print(st);

    // REVERESE A STACK (IN PLACE)
    // stack<int> st;
    // st.push(10);
    // st.push(20);
    // st.push(30);
    // st.push(40);
    // st.push(50);
    // cout << "Before Reversing: ";
    // print(st);
    // reverseStack(st);
    // cout << "After Reversing: ";
    // print(st);

    // INSERT IN A SORTED STACK
    // stack<int> st;
    // st.push(10);
    // st.push(20);
    // st.push(30);
    // st.push(40);
    // st.push(50);
    // int elem = 25;
    // insertIntoSortedStack(st, elem);
    // print(st);

    // SORT A STACK
    stack<int> st;
    st.push(9);
    st.push(8);
    st.push(12);
    st.push(5);
    st.push(10);
    sortStack(st);
    print(st);

}