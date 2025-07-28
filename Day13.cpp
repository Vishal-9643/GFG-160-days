// Day 13 : Smallest +ve Missing Number.

#include<bits/stdc++.h>
using namespace std;

int missingNumber(vector<int> &arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        int k = 1;
        for(int i=0;i<n;i++){
            if(k == arr[i])
            k++;
            else if(k<arr[i])
            break;
        }
        return k;
        
}

int main(){
    vector<int> Arr = {2, -3, 4, 1, 1, 7};
    int ans = missingNumber(Arr);
    cout << ans;
}