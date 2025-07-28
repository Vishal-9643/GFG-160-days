// Day 8 : Stock Buy & Sell Max one transaction allowed.

  // Approach is assuming first day as bestBuy and traversing the data if price greater  than bestBuy then calculate profit and if less make it bestbuy.

#include<bits/stdc++.h>
using namespace std;

int maximumProfit(vector<int> &prices) {
        int n = prices.size();
        int MP =0;
        int BB = prices[0]; // Best BUY.
        for(int i=1;i<n;i++){
            if(BB<prices[i]){
                int profit = prices[i]-BB;
                MP = max(profit,MP);
            }else{
                BB = min(BB,prices[i]);
            }
        }
        return MP;
}

int main(){
    vector<int> Stock = {7, 10, 1, 3, 6, 9, 2};
    int MP = maximumProfit(Stock);
    cout << MP;
}