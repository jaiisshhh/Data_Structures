#include<iostream>
#include<map> 
using namespace std;

void countChar(unordered_map<char,int> &mp, string str){
    for(char ch : str){
        mp[ch]++;
    }
} 

int main(){
    // // Creation 
    // unordered_map<string, int> mapping;
    // // Insertion
    // pair<string, int> p = make_pair("heloo", 25);
    // pair<string, int> q("world", 22);
    // pair<string, int> r;
    // r.first = "Arjun";
    // r.second = 21;
    // mapping["wow"] = 1;

    // mapping.insert(p);
    // mapping.insert(q);
    // mapping.insert(r);

    // cout << "Size of map : " << mapping.size() << endl;

    // // Accessing 

    // // Print where key is x
    // cout << mapping.at("hello") << endl;
    // cout << mapping["hello"] << endl;  

    // cout << mapping.count("wow") << endl; // Either 0 or 1
    
    //  if(mapping.find("hello") != mapping.end()){
    //     cout << "Found" << endl;
    // }
    // else cout<< "Not Found" << endl;

    // FIND FREQ OF LETTERS IN A STRING
    string str = "lovebabbar";
    unordered_map<char, int> mp;
    countChar(mp, str);
    for(auto i : mp){
        cout << i.first << " -> " << i.second << endl;
    }
}