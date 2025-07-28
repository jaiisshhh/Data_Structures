#include<iostream>
#include<vector>
using namespace std;

class TrieNode{
public : 
    char value;
    TrieNode* childern[26]; // Dynamic array of pointer
    bool isTerminal;

    TrieNode(char val){
        this -> value = val;
        for(int i=0;i<26;i++){
            childern[i] = NULL;
        }
        this -> isTerminal = false;
    }
};

void insertWord(TrieNode* root, string word){
    //cout << "Recived word : " << word << " for insertion" << endl;
    if(!word.length()){ 
        root -> isTerminal = true;
        return;
    } 
    char ch = word[0];
    int index = ch - 'a';
    TrieNode* child;
    if(root -> childern[index] != NULL){
        // Child Present
        child = root -> childern[index];
    }
    else{
        // Child Absent
        child = new TrieNode(ch);
        root -> childern[index] = child;
    }
    insertWord(child, word.substr(1));
}

bool searchWord(TrieNode* root, string word){
    if(!word.length()) return root -> isTerminal;
    char ch = word[0];
    int index = ch - 'a';
    TrieNode* child;
    if(root -> childern[index] != NULL){
        // Found
        child = root -> childern[index];
    }
    else{
        // Not Found
        return false;
    }
    bool recAns = searchWord(child, word.substr(1));
    return recAns;
}

void deleteWord(TrieNode* root, string word){
    if(!word.length()){
        root -> isTerminal = false;
        return;
    }
    char ch = word[0];
    int index = ch - 'a';
    TrieNode* child;
    if(root -> childern[index] != NULL){
        child = root -> childern[index];
    }
    else{
        return;
    }
    deleteWord(child, word.substr(1));
}

void storeString(TrieNode* root, vector<string>& suffix, string& input, string& prefix){
    if(root -> isTerminal) suffix.push_back(prefix + input);
    for(char ch = 'a'; ch <= 'z'; ch++){
        int index = ch - 'a';
        TrieNode* next = root -> childern[index];
        if(next != NULL){
            // Child Existes
            input.push_back(ch);
            storeString(next, suffix, input, prefix);
            input.pop_back();
        }
    }
}

void findPrefixString(TrieNode* root, string input, vector<string> &ans, string& prefix){
    if(!input.length()){
        TrieNode* lastchar = root;
        storeString(lastchar, ans, input, prefix);
        return;
    }
    char ch = input[0];
    int index = ch - 'a';
    TrieNode* child;
    if(root -> childern[index]){
        // Child present
        child = root -> childern[index];
    }
    else{
        return;
    }
    findPrefixString(child, input.substr(1), ans, prefix);
}

int main(){
    TrieNode* root = new TrieNode('-');
    insertWord(root, "cater"); 
    insertWord(root, "care"); 
    insertWord(root, "com"); 
    insertWord(root, "lover"); 
    insertWord(root, "loved"); 
    insertWord(root, "load"); 
    insertWord(root, "lov"); 
    insertWord(root, "bat"); 
    insertWord(root, "cat"); 
    insertWord(root, "car"); 
    cout << "Insertion Done !" << endl;

    // if(searchWord(root, "loved")){
    //     cout << "Found" << endl;
    // }
    // else{ 
    //     cout << "Not Found" << endl;
    // }

    // deleteWord(root, "loved");
    // cout << "Word Deleted !" << endl;
    // if(searchWord(root, "loved")){
    //     cout << "Found" << endl;
    // }
    // else{ 
    //     cout << "Not Found" << endl;
    // }

    string input = "c";
    string prefix = input;
    vector<string> ans;
    findPrefixString(root, input, ans, prefix);
    for(auto i : ans){
        cout << i << " ";
    }
    cout << endl;
    
}