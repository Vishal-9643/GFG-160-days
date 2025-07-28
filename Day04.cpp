// Day 4 : Rotate the array to the left by D steps.

#include<bits/stdc++.h>
using namespace std;

//function to rotate the array.
void rotate(vector<int> & arr , int D){
    int n = arr.size();
    D = D%n; // handle the case when D>n;
    int temp[n]; // creating temp arr.
    int j =0;
    for(int i =D;i<n;i++){
        temp[j++] = arr[i];
    }
    for(int i =0;i<D;i++){
        temp[j++] = arr[i];
    }
    for(int i =0;i<n;i++){
        arr[i] = temp[i];
    }
}

int main(){
    vector<int> arr = {1,2,3,4,5,6};
    rotate(arr,2);
    for(int num:arr){
        cout << num << " ";
    }
}