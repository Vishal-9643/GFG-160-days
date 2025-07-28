// Day 11 : Maximum Subarray Product.

#include<bits/stdc++.h>
using namespace std;

int maxProduct(vector<int> &arr) {
        int n = arr.size();
        int maxP = INT_MIN;
        int LR = 1;
        int RL =1;
        for(int i=0;i<n;i++){
            if(LR==0)
            LR = 1;
            if(RL==0)
            RL = 1;
            
            LR = LR * arr[i];
            int j = n-1-i;
            RL = RL * arr[j];
            maxP = max({maxP,LR,RL});
            
        }
        return maxP;
}

int main(){
    vector<int> array = {-2, 6, -3, -10, 0, 2};
    int ans = maxProduct(array);
    cout << ans;
}