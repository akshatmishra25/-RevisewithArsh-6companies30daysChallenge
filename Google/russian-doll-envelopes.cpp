// Problem Link - https://leetcode.com/problems/russian-doll-envelopes/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    static bool cmp(vector<int>& a, vector<int>& b){
        if(a[0]==b[0]) return a[1] > b[1];
        return a[0] < b[0];
    }
public:
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), cmp);
        vector<int> dp;
        vector<int> h;
        for(int i=0; i<envelopes.size(); i++){
            int element = envelopes[i][1];
            int nextIndex= lower_bound(dp.begin(), dp.end(), element)-dp.begin();

            if(nextIndex>=dp.size()) dp.push_back(element);
            else dp[nextIndex]=element;
        }
        
        return dp.size();
    }
};