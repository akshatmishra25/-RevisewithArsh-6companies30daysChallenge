// Problem Link - https://leetcode.com/problems/combination-sum-iii/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  void combination(vector<vector<int>>& result, vector<int> res, int k, int n) {
    if (res.size() == k && n == 0) { 
        result.push_back(res); 
        return; 
        }
    if (res.size() < k) {
      for (int i = res.empty() ? 1 : res.back() + 1; i <= 9; ++i) {
        if (n - i < 0) break;
        res.push_back(i);
        combination(result, res, k, n - i);
        res.pop_back();
      }
    }
  }

  vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> result;
    vector<int> res;
    combination(result, res, k, n);
    return result;
  }
};