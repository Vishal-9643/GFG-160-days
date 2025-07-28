// Day 9 : Minimize Height II 
//  Approach : S1. first sort the array
            // S2. Intializing Min and Max and Difference is max- min.
            // S3. if arr[i]-k>0 then find new min and max and new diffrence is minimum of previous and curret.
#include<bits/stdc++.h>
using namespace std;

int getMinDiff(vector<int> &arr, int k) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        int Min = arr[0]+k;
        int Max =arr[n-1]-k;
        int D = arr[n-1]-arr[0];
        for(int i=1;i<n;i++){
            if(arr[i]-k>0){
                int a = min(Min,arr[i]-k);
                int b= max(Max,arr[i-1]+k);
                D= min(D,b-a);
            }
            
        }
        
        return D;
        
}

int main(){
    vector<int> tower = {1, 5, 8, 10};
    int ans = getMinDiff(tower,2);
    cout << ans ;
}