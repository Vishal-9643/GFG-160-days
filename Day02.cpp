// Day 2 : Moving all zero at the end of an array.

#include<bits/stdc++.h>
using namespace std;

// Function for moving zero at end;
 void Move(vector<int> & arr){
    int n = arr.size();
    int temp[n]; // creating temporary arr.
    int j = 0;
    for(int i=0;i<n;i++){
        if(arr[i]!=0){
            temp[j] = arr[i]; // copying all non zero element into temp arr.
            j++;
            }
    }
    while(j<n){
        temp[j]=0; // filling zero in remaing space of temp.
        j++;
    }
    for(int i=0;i<n;i++){
        arr[i] = temp[i]; // copying temp into main array.
    }
    
 }

int main(){
    vector<int> arr = {10,20,0,30,0,70,8,0,0,0};
    Move(arr);
    // printing array.
    for(int num : arr){
        cout << num << " ";
    }

}
