#include <iostream>
#include <stack>
using namespace std;

class Stack{
    public: 
    int *arr;
    int size;
    int top1;
    int top2;
    Stack(int size){
        arr = new int[size];
        this -> size = size;
        top1 = -1;
        top2 = size;
    }
    void push1(int data){
        if(top2 - top1 == 1){
            cout << "OVERFLOW" << endl;
        }
        else{
            top1++;
            arr[top1] = data;
        }
    }
    void push2(int data){
        if(top2 - top1 == 1){
            cout << "OVERFLOW" << endl;
        }
        else{
            top2--;
            arr[top2] = data;
        }
    }
    void pop1(){
        if(top1 == -1){
            cout << "UNDERFLOW" << endl;
        }
        else{
            arr[top1] = 0;
            top1--;
        }
    }
    void pop2(){
        if(top2 == size){
            cout << "UNDERFLOW" << endl;
        }
        else{
            arr[top2] = 0;
            top2++;
        }
    }
    void print(){
        cout << "Top 1 : " << top1 << endl;
        cout << "Top 2 : " << top2 << endl;
        cout << "Stack : "; 
        for(int i=0; i<size; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

bool checkRedundent(string &str){
    stack<char> st;
    for(int i=0; i<str.length(); i++){
        char ch = str[i];
        if(ch == '(' || ch =='+' || ch == '-' || ch == '*' || ch == '/'){
            st.push(ch);
        }
        else if(ch == ')'){
            int opCount = 0;
            while(!st.empty() && st.top() != '('){
                char temp = st.top();
                if(temp =='+' || temp == '-' || temp == '*' || temp == '/'){
                    opCount++;
                }
                st.pop();
            }
            st.pop();
            if(opCount == 0){
                return true;
            }
        }
    }
    return false;
}

int main(){
    // Stack st(6);
    // st.print();

    // REDUNDNET BRACKET 
    string str = "((a+b)*(c+d))";
    bool ans = checkRedundent(str);
    if(ans == true){
        cout << "Redundent Bracket Present" << endl;
    }
    else{
        cout << "Redundent Bracket Not Present" << endl;
    }

    return 0;
}