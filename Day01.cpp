// Day 1 : Finding the second largest element from an array.

#include<bits/stdc++.h>
using namespace std;

// Function for finding second largest element.
int SL(vector<int> & arr){
    int n = arr.size();
    int largest = INT16_MIN;
    int Slargest = INT16_MIN;

    for(int i=0;i<n;i++){
        if(arr[i]>largest){
            Slargest = largest;
            largest = arr[i];
        }else if(arr[i]<largest && arr[i]>Slargest){
            Slargest = arr[i];

        }
    }
    return Slargest;
}

int main(){
    vector<int> arr = {12 , 10 , 16 , 89, 67};
    cout << SL(arr);
    return 0;
}
