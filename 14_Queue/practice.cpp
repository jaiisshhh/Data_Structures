#include<iostream>
#include<queue>
using namespace std;

void firstNonRepChar(string str){
    queue<char> q;
    int freq[26] = {0}; // intitalize freq table with 0
    for(int i=0; i<str.length(); i++){
        char ch = str[i];
        freq[ch - 'a']++;
        q.push(ch);
        while(!q.empty()){
            char frontChar = q.front();
            if(freq[frontChar - 'a'] > 1){
                q.pop();
            }
            else{
                cout << frontChar << " ";
                break;
            }
        }
        if(q.empty()){
            cout << "#" << " ";
        }
    }
}

int main(){
    // FIRST NON REPETING CHARATER IN A STREAM
    string str = "ababc";
    firstNonRepChar(str);
    
}