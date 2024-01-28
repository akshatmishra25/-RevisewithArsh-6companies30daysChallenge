// Problem Link - https://leetcode.com/problems/count-number-of-nice-subarrays/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        vector<int> odd;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]&1){
                odd.push_back(i);
            }
        }
        if(odd.size()<k) return 0;
        int i=0, j=k-1;
        int ans = 0;
        while(j<odd.size()){
            int left, right;
            if(i==0){
                if(odd[0]==0){
                    left=1;
                }
                else{
                    left = odd[i]+1;
                }
            }
            else{
                left = odd[i]-odd[i-1];
            }
            if(j==odd.size()-1){
                if(odd[j]==nums.size()-1){
                    right = 1;
                }
                else{
                    right = nums.size()-odd[j];
                }
            }
            else{
                right = odd[j+1]-odd[j];
            }
            ans+=(left*right);
            i++;
            j++;
        }
        return ans;
    }
};