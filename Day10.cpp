// Day 10 : Maximum Subarray sum using Kadane's Algorithm.
// Approach using tarversing array and add each elemnt into current sum and finding maxsum from current sum and maxsum and if current sum is less than zero make it zero.

#include<bits/stdc++.h>
using namespace std;

int maxSubarraySum(vector<int> &arr) {
        
        int MaxSum = INT_MIN;
        int currSum = 0;
        int n = arr.size();
        for(int i=0;i<n;i++){
             currSum = currSum + arr[i];
             MaxSum = max(MaxSum,currSum);
            if(currSum<0){
                currSum = 0;
            }
           
        }
        return MaxSum;
}

int main(){
    vector<int> arr = {2, 3, -8, 7, -1, 2, 3};
    int ans = maxSubarraySum(arr);
    cout << ans;
}

