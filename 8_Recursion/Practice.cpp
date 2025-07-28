#include<iostream> 
#include<vector>
using namespace std;

bool isPelindrome(string& s, int start, int end){
    if(start >= end) return true;
    if(s[start] != s[end]) return false;
    return isPelindrome(s, start + 1, end - 1);
}

void lastOcurrLtoR(string& s, char ch,int i, int& ans){
    if(i >= s.size()){
        return;
    }
    if(s[i] == ch){
        ans = i;
    }
    lastOcurrLtoR(s,ch,i+1,ans);
}

void lastOcurrRtoL(string& s, char ch, int i, int& ans){
    if(i < 0){
        return;
    }
    if(s[i] == ch){
        ans = i;
        return;
    }
    lastOcurrLtoR(s,ch,i-1,ans);
}

void reverse(string& s, int start, int end){
    if(start >= end){
        return;
    }
    swap(s[start],s[end]);
    reverse(s,start+1,end-1);
}

void printSubArray(vector<int> arr,int start, int end){
    if(end == arr.size()) return;
    for(int i=start; i<= end; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    printSubArray(arr, start, end + 1);
}
void printSubArrayHelper(vector<int> arr){
    for(int start = 0; start <= arr.size(); start++){
        int end = start;
        printSubArray(arr,start,end);
    }
}

int main(){
    // PELINDROME CHECK
    // string s;
    // cin >> s;
    // cout << isPelindrome(s, 0, s.size() - 1) << endl;

    // LAST OCCURENCE OF A CHAR
    // string s;
    // cin >> s;
    // char x;
    // cin >> x;
    // int ans = -1;
    // // lastOcurrLtoR(s,x,0,ans);
    // // cout << ans << endl;
    // lastOcurrRtoL(s,x,s.size() - 1,ans);
    // cout << ans << endl;

    // REVERSE A STRING
    // string s;
    // cin >> s;
    // reverse(s,0,s.size()-1);
    // cout << s << endl;

    // PRINT ALL SUBARRAY USING RECURSION
    vector<int> arr = {1,2,3,4,5};
    printSubArrayHelper(arr);
}