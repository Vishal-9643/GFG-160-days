// Day 6 : Majority Element - More than N/3.

#include<bits/stdc++.h>
using namespace std;

 vector<int> findMajority(vector<int>& arr) {
        int n = arr.size();
        int num1 = 0, num2 = 1;
        int count1 =0 , count2 = 0;
        for(int i=0;i<n;i++){ // loop for storing major number in num1 and num2.
            if(arr[i]==num1)
            count1++;
            else if(arr[i]==num2  )
            count2++;
            else if(count1==0){
                num1 = arr[i];
                count1 = 1;
            }else if(count2==0){
                num2 = arr[i];
                count2 = 1;
            }else{
                count1--;
                count2--;
            }
        }
        count1 = count2 = 0;
        for(int i=0;i<n;i++){ // Loop for counting majority number presence.
            if(arr[i]==num1)
            count1++;
            else if(arr[i]==num2)
            count2++;
        }
        vector<int> V;
        if(count1>n/3)
        V.push_back(num1);
        if(count2>n/3)
        V.push_back(num2);
        
        if(V.size()==2 && V[0]>V[1])
        swap(V[0],V[1]);
        
        return V;
}

int main(){
    vector<int> arr = {2,2,3,1,3,2,1,1};
    vector<int> ans = findMajority(arr);
    for(int i: ans){
        cout << i << " ";
    }
}
