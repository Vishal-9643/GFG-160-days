// Day 5 :  Find Next Permutation of an array.
// S1 : Find the pivot index. eg : [1,2 ,3] here pivot index is 1 and pivot element is 2.(pivot element is those a[i]<a[i+1] from backward.)
// S2 : if pivot not found tha mens its is last permutation . eg : [3,2,1] then its next permutation is its reverse .
// S3 : Find rightmost elemnet greater than pivot element and swap with pivot. eg : [1,2,3] becomes [1,3,2];
// S4 : Reverse the array after pivot index to the end .

#include<bits/stdc++.h>
using namespace std;

// function for next permutation.
void NexPer(vector<int> & arr){
    int n = arr.size();
    int pivot = -1;
    for(int i = n-2;i>=0;i--){ // finding pivot index from backward.
        if(arr[i]<arr[i+1]){
            pivot = i;
            break;
        }
    }
    if(pivot == -1){ // if pivot not found then its is last permuatation so reverse it and get first one.
        reverse(arr.begin(),arr.end());
        return;
    }
    for(int i=n-1;i>pivot;i--){ // finding rightmost greater element than pivot and swap it.
        if(arr[i]>arr[pivot]){
            swap(arr[i],arr[pivot]);
            break;
        }
    }
    int k = pivot+1;
    reverse(arr.begin()+k,arr.end());
}

int main(){
    vector<int> arr = {2,4,1,7,5,0};
    NexPer(arr);
    for(int i : arr){
        cout << i << " ";
    }
}