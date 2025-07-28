#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

int findLength(char ch[], int size){
    int index = 0;
    while(ch[index] != '\0'){
        index++;
    }
    // int length = 0;
    // for(int i=0; i<size; i++){
    //     if(ch[i] == '\0'){
    //         break;
    //     }
    //     else{
    //         length++;
    //     }
    // }
    return index;
}

void ReverseStr(char ch[], int size){
    int start = 0, end = size - 1;
    while(start < end){
        swap(ch[start],ch[end]);
        start++;
        end--;
    }
}

void convertToUpperCase(char ch[], int size){
    int index = 0;
    while(ch[index] != '\0'){
        if(ch[index] >= 'a' && ch[index] <= 'z'){
            ch[index] = ch[index] - 'a' + 'A';
        }
        index++;
    }
}

void replace(char ch[], int size){
    int index = 0;
    while(ch[index] != '\0'){
        if(ch[index] == '@'){
            ch[index] = ' ';
        }
        index++;
    }
}

bool checkPelindrome(char ch[], int size){
    int i = 0, j = size - 1;
    while( i <= j ){
        if(ch[i] == ch[j]){
            i++;
            j--;
        }
        else{
            return false;
        }
    }
    return true;
}

int main(){

    // CHARACTER ARRAYS !!!

    // Creation
    // char ch[100];

    // cin >> ch;
    // With space inputs
    // cin.getline(ch,100);

    // cout << "Printing character : " << ch << endl;
    // cout << "Accessing the second index : " << ch[2] << endl;

    // // Printing using loop
    // for(int i=0; i<10; i++){
    //     cout << "At index " << i << "  " << ch[i] << endl;
    // } //For Sanskar 

    // //Null char
    // int temp = ch[8];
    // int value = (int)temp;
    // cout << "The value of the null character is " << value << endl; 

    // FIND THE LENGHT OF A STRING IN A CHAR ARRAY
    // int len = findLength(ch, 100);
    // // cout << "Length of the char array is " << len << endl;
    // cout << "Length of the char array is " << strlen(ch) << endl;

    // REVERSE A STRING 
    // char ch[10];
    // cin >> ch;
    // // int len = strlen(ch);
    // // ReverseStr(ch,len);
    // // cout << ch << endl;
    // // USING STL
    // reverse(ch , ch + strlen(ch));
    // cout << ch << endl;

    //CONVERT TO UPPER CASE
    // char ch[20];
    // cin.getline(ch,20);
    // convertToUpperCase(ch,strlen(ch));
    // cout << ch << endl;

    //REPLACE @ WITH SPACES
    // char ch[20];
    // cin.getline(ch,20);
    // replace(ch,strlen(ch));
    // cout << ch << endl;

    //CHECK PELINDROME V.IMP
    // char ch[10];
    // cin >> ch;
    // bool ans = checkPelindrome(ch, strlen(ch));
    // if(ans == true){
    //     cout << "is a valid pelindrome" << endl;
    // }
    // else{
    //     cout << "Not a valid pelindrome" << endl;
    // }

    //-----------------********---------------------------------


    // STRINGS

    string str;
    cin >> str;
    // cout << str << endl;
    // cout << "Printing first charactrer of string : " << str[0] << endl; 
    // cout << str[6] << endl; //Printing the null value for Hello
    // int ascaii = int(str[6]);
    // cout << ascaii << endl;

    cout << "length of string " << str.length() << endl;

    return 0;
}