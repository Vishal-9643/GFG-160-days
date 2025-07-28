// Day 3 : Reverse a given array.

#include<bits/stdc++.h>
using namespace std;

// function for reversing  array.
void reverse(vector<int> & arr){
    int n = arr.size();
    int st = 0;
    int end = n-1;
    while(st<end){
        swap(arr[st],arr[end]);
        st++;
        end--;
    }
}

int main(){
    vector<int> arr = {1,2,3,4,5,6};
    reverse(arr);
    for(int num:arr){
        cout << num << " ";
    }
}