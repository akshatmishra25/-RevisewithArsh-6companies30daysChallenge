// Problem Link - https://leetcode.com/problems/random-flip-matrix/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mx = 0;
    int row = 0;
    int col = 0;
    unordered_set<int> v;
    Solution(int m, int n) {
        mx = m * n;
        row = m;
        col = n;
    }
    
    vector<int> flip() {
        if(v.size() == mx) return {};
        int r = rand() % mx;
        while(v.count(r)) {
            r = (++r) %mx;
        }
        v.insert(r);
        return {r / col, r % col };
    }
    
    void reset() {
        v = {};
    }
};
