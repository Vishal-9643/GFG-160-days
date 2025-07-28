// Day 7 : Stock Buy & Sell Multiple Transaction Allowed.

#include<bits/stdc++.h>
using namespace std;
// approach is if next day price is greater than current then buy and sell on next day and claculate profit.
int maximumProfit(vector<int> &arr) {
        int n = arr.size();
        int MP =0;
        for(int i=0;i<n-1;i++){
            if(arr[i]<arr[i+1]){ // If next day price high then profit calculating.
                MP += arr[i+1]-arr[i];
            }
        }
        return MP;
}

int main(){
    vector<int> Stock = {100, 180, 260, 310, 40, 535, 695};
    int MaxProfit = maximumProfit(Stock);
    cout << MaxProfit;
}