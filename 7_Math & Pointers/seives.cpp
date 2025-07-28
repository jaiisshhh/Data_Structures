#include<iostream>
#include<vector>
#include<math.h> //For sqrt
using namespace std;

vector<bool> simpleSeive(int n){
    // CREATE A SEIVE ARRAY
    vector<bool> seive(n+1,true);
    seive[0] = seive[1] = false;
    for(int i=2; i<=sqrt(n);i++){
        if(seive[i] == true){
            int j = i * i;
            while(j<n){
                seive[j] = false;
                j += i;
            }
        }
    }
    return seive;
}

vector<bool> segmentedSeive(int left, int right){
    // Get prime numbers array
    vector<bool> seive = simpleSeive(sqrt(right));
    vector<int> basePrime;
    for(int i=0; i<seive.size();i++){
        if(seive[i]){
            basePrime.push_back(i); 
        }
    }

    vector<bool> segSeive(right - left + 1, true);
    if(left == 1 || left == 0){
        segSeive[0] = false; 
    }
    for(auto prime:basePrime){
        int firstMultiple = (left/prime)*prime;
        if(firstMultiple < left){
            firstMultiple += prime; 
        }
        int j = max( firstMultiple , prime*prime );
        while(j<=right){
            segSeive[j - left ] = false;
            j += prime;
        }
    }
    return segSeive;
}

int main(){

    // SIMPLE SEIVE
    // vector<bool> seive = simpleSeive(25);
    // for(int i=0; i<=25; i++){
    //     if(seive[i]){
    //         cout << i << " "; 
    //     }
    // }

    // SEGMENTED SEIVE
    int low = 110;
    int high = 130;
    vector<bool> segSeive = segmentedSeive(low,high);
    for(int i=0; i<segSeive.size();i++){
        if(segSeive[i]){
             cout << i + low << " ";
        }
    }

    return 0;
}
