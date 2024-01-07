// Problem Link - https://leetcode.com/problems/count-the-number-of-incremovable-subarrays-i/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
      int ans = 0, n=nums.size(); 
      for(int i=0; i<n; i++){
          for(int j=i; j<n; j++){
              int last = -1, flag = 1;
            for(int k = 0; k < nums.size(); ++k){
                if(k >= i && k <= j) continue;
                if(last >= nums[k]){ flag = 0; break; }
                last = nums[k];
            }
            if(flag) ans++;
          }
      }
      return ans;  
    }
};