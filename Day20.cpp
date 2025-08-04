// // Day 20 : H-Index (Given an integer array citations[], where citations[i] represents the number of citations for the ith paper, you have to compute the H-index of the researcher.The H-index is defined as the maximum value H such that the researcher has at least H papers with at least H citations each.).

#include<bits/stdc++.h>
using namespace std;

int hIndex(vector<int>& citations) {
        // Using Counting Sort Algo.
        int n = citations.size();
        vector<int> freq(n+1,0);
        
        for(int i=0;i<n;i++){
            if(citations[i]>=n){
                freq[n]++;
            }else{
                freq[citations[i]]++;
            }
        }
        
        int idx = n;
        
        int sum = freq[n];
        while(sum<idx){
            idx--;
            sum+= freq[idx];
        }
        return idx;
    }

int main(){
    vector<int> Citation = {5, 1, 2, 4, 1};
    int ans = hIndex(Citation);
    cout << ans;
} 