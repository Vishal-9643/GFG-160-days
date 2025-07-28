// Day 12 : Max Circular Subarray Sum.

#include<bits/stdc++.h>
using namespace std;

int circularSubarraySum(vector<int> &arr) {
        int n = arr.size();
        int Tsum = 0;
        int Maxsum = INT_MIN;
        int MinSum = INT_MAX;
        int Cmin = 0;
        int Cmax = 0;
        for(int i=0;i<n;i++){
            Tsum += arr[i];
            Cmax += arr[i];
            Cmin += arr[i];
            Maxsum = max(Maxsum , Cmax);
            MinSum = min(MinSum,Cmin);
            if(Cmax<0)
            Cmax = 0;
            if(Cmin>0)
            Cmin = 0;
        }
        int CirSum = Tsum-MinSum;
        if(Tsum == MinSum)
        return Maxsum;
        
        return max(Maxsum,CirSum);
}

int main(){
    vector<int> arr = {8, -8, 9, -9, 10, -11, 12};
    int ans = circularSubarraySum(arr);
    cout << ans;
}