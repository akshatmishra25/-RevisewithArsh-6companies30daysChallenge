// Problem Link - https://leetcode.com/problems/k-diff-pairs-in-an-array/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        int ans = 0;
        for(auto it : mp){
            int x = it.first;
            if(k==0){
                if(it.second>1) ans++;
            }
            else if(mp.find(x+k)!=mp.end()){
                ans++;
            }
        }
        return ans;       
    }
};