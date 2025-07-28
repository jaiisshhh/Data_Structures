#include <iostream>
using namespace std;

void solve(int arr[], int size){
    cout << "Inside function arr : " << arr << endl;
    cout << "Inside function &arr : " << &arr << endl; // Should be different then the rest
}

int main(){

    int a = 5;
    cout << "Value at a is :  " << a << endl;
    cout << "Address of a : " << &a << endl;

    // Pointer creation
    int* ptr = &a;

    cout << "Size of a pointer : " << sizeof(ptr) << endl;

    cout << "What is inside ptr ? : " << ptr << endl;

    // Address of ptr
    cout << "Address of ptr : " << &ptr << endl;

    // Accessing vlaue stored int ptr
    cout << "Accessing the value at ptr : " << *ptr << endl;

    cout << endl;

    // Sizes
    int integer = 10;
    char character = 'a';
    bool boolean = true;
    long long longInteger = 15;

    cout << "Size of int : " << sizeof(integer) << endl;
    cout << "Size of char : " << sizeof(character) << endl;
    cout << "Size of bool : " << sizeof(boolean) << endl;
    cout << "Size of long long : " << sizeof(longInteger) << endl;

    cout << endl;

    int* intPtr = &integer;
    char* charPtr = &character;
    bool* boolPtr = &boolean;
    long long* longPtr = &longInteger;

    cout << "Size of int pointer : " << sizeof(intPtr) << endl;
    cout << "Size of char pointer : " << sizeof(charPtr) << endl;
    cout << "Size of bool pointer : " << sizeof(boolPtr) << endl;
    cout << "Size of long long pointer : " << sizeof(longPtr) << endl;

    cout << endl;

    int arr[] = {1,2,3,4,5};
    solve(arr,5);
    cout << "Inside main arr : " << arr << endl;
    cout << "Inside main &arr : " << &arr << endl;
    return 0;
}