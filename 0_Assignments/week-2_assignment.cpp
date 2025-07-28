#include <iostream>
using namespace std;

// float areaOfCircle(float radius){
//     float area = 3.14 * radius * radius;
//     return area;
// } 

// bool evenOdd(int n){
//     if(n%2==0){
//         return true;
//     }
//     else{
//         return false;
//     }
// }

// bool bitwiseevenOdd(int n){
//     if((n&1)==0){
//         return true;
//     }
//     else{
//         return false;
//     }
// }

// int factorial(int n){
//     int fact = 1;
//     for(int i=1; i<=n; i++){
//         fact = fact * i;
//     }
//     return fact;
// }

// bool checkPrime(int n){
//     for(int i=2; i<n; i++){
//         if(n%i==0){
//             return false;
//         }
//     }
//     return true;
// }

// int setBits(int n){
//     int count = 0;
//     while(n>0){
//         int bit = n % 2;
//         if( bit == 1){
//             count++;
//         }
//         bit = n / 2;
//     }
//     return count;
// }

// int createNumUsingDigits(int numberOfDigits){
//     int num = 0;
//     for(int i=0; i<numberOfDigits; i++){
//         cout << "Enter the digits : " << endl;
//         int digit; cin >> digit;
//         num = num * 10 + digit;
//     }
//     return num;
// }

// void printAllDigit(int n){
//     while(n > 0){
//         int onesPlaceDegit = n%10;
//         cout << "Digit : " << onesPlaceDegit << endl;
//         n /= 10;
//     }
// }

// void convert(int km){
//     float miles = km * 0.621371;
//     cout << miles << endl;
// }

int main(){

    // NUMERIC HALF PYRAMID
    // int n; cin>>n;
    // for(int row=0; row<n; row++){
    //     for(int col=0; col<=row; col++){
    //         cout << col+1<<" ";
    //     }
    //     cout<<endl;
    // }

    // NUMERIC HOLLOW HALF PYRAMID
    // int n; cin>>n;
    // for(int row=0; row<n; row++){
    //     for(int col=0; col<=row; col++){
    //         if(col==0 || col==row || row==n-1){
    //             cout << col+1<<" ";
    //         }    
    //         else{
    //             cout << "  ";
    //         }
    //     }
    //     cout<<endl;
    // }

    // NUMERIC INVERDET HALF PYRAMID
    // int n; cin>>n;
    // for(int i=0; i<n; i++){
    //     for(int j=i+1; j<=n; j++){
    //         if(j==i+1 || j==n || i==0){
    //             cout << j << " ";
    //         }
    //         else{
    //             cout << "  ";
    //         }
    //     }
    //     cout << endl;
    // }

    // NUMERIC PELINDROME TRIANGLE 
    // int n; cin >> n;
    // int k=n;
    // for(int i=0; i<n; i++){
    //     int c = 1;
    //     for(int j=0; j<k; j++){
    //         if(j<n-i-1){
    //             cout << " "; 
    //         }
    //         else if(j<=n-1){
    //             cout << c;
    //             c++;
    //         }
    //         else if(j==n){
    //             c = c-2;
    //             cout << c;
    //             c--;
    //         }
    //         else{
    //             cout << c;
    //             c--;
    //         }
    //     }
    //     k++;
    //     cout << endl;
    // }

    // SOLID HALF DIMOND
    // int n; cin >> n;
    // for(int i=0; i<2*n-1; i++){
    //     int cond = 0;
    //     if(i<n){
    //         cond = i;
    //     }
    //     else{
    //         cond = n-(i%n)-2;
    //     }
    //     for(int j=0; j<=cond; j++){
    //         cout << "* ";
    //     }
    //     cout << endl;
    // }

    // FLOYED'S TRIANGLE
    // int n; cin >> n;
    // int c = 1;
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<=i; j++){
    //         cout << c << " ";
    //         c++;
    //     }
    //     cout << endl;
    // }

    // PASCALS'S TRAINGLE
    // int n; cin >> n;
    // for(int i=1; i<=n; i++){
    //     int c = 1;
    //     for(int j=1; j<=i; j++){
    //         cout << c << " ";
    //         c = c * (i - j) / j;  //Formula
    //     }
    //     cout << endl;
    // }

    // AREA OF CIRCLE 
    // int radius; cin >> radius;
    // cout << "Area of the circle is " << areaOfCircle(radius) << endl;

    // EVEN ODD
    // int n;
    // cin >> n;
    // bool ans = evenOdd(n);
    // if(ans == true){
    //     cout << "Given value is even" << endl;
    // }
    // else{
    //     cout << "Given value is odd" << endl;
    // }

    // FACTORIAL
    // int n;
    // cin >> n;
    // cout << "Factorial of " << n << " is " << factorial(n) << endl; 
    
    // PRIME OR NOT
    // int n; cin >> n;
    // bool isPrime = checkPrime(n);
    // if(isPrime == true){
    //     cout << "The number is a prime" << endl;
    // }
    // else{
    //     cout << "The number is not a prime number" << endl;
    // }

    // PRINT ALL PRIME NUMBERS FORM 1 TO N
    // int n; cin >> n;
    // for(int i=1; i<=n; i++){
    //     if(checkPrime(i)==true){
    //         cout << i << " ";
    //     }
    // }

    // REVERSE INTEGER
    // int x; cin >> x;
    // int ans, rem = 0;
    // bool isNeg = false;
    // if(x<0){
    //     isNeg = true;
    //     x = -x;
    // }
    // while(x>0){
    //     if(ans > INT_MAX/10){
    //         return 0;
    //     }
    //     int digit = x % 10;
    //     ans = ans * 10 + digit;
    //     x = x/10;
    // }
    // int finalAns = isNeg ? -ans : ans;
    // cout << finalAns << endl;

    // COUNT ALL SET BITS
    // int n; cin >> n;
    // int countSetBits = setBits(n);
    // cout << countSetBits << endl;

    // CREATE NUMBERS USING DIGITS
    // int numberOfDigits; cin >> numberOfDigits;
    // int num = createNumUsingDigits(numberOfDigits);
    // cout << num << endl;

    // PRINT ALL DIGITS OF AN INTIGER
    // int n; cin>> n;
    // printAllDigit(n);

    // CONVERT KM TO MILES
    // float km; cin >> km;
    // convert(km);

    return 0;
}