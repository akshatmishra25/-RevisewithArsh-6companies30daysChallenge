// Problem Link - https://leetcode.com/problems/query-kth-smallest-trimmed-number/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        for (int i = 0; i < queries.size(); i++) {
            int k = queries[i][0];
            priority_queue<pair<string,int>, vector<pair<string, int>>, greater<pair<string, int>>> pq;
            for (int j = 0; j < nums.size(); j++) {
                string cur = nums[j];
                int len = queries[i][1];
                int pos = cur.size() - len;
                if (pos >= 0 && pos < cur.size()) {  // Check if pos is within bounds
                    string val = (cur.substr(pos, len));
                    pq.push({val, j});
                }
            }
            int top;
            while(!pq.empty() && k--){
                top=pq.top().second;
                pq.pop();
            }
            ans.push_back(top);
        }
        return ans;
    }
};
