// Problem Link - https://leetcode.com/problems/sort-characters-by-frequency/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for(int i=0; i<s.size(); i++){
            mp[s[i]]++;
        }
        vector<pair<int, char>> v;
        for(auto it: mp){
            v.push_back({it.second, it.first});
        }
        sort(v.rbegin(), v.rend());
        string ans = "";
        for(int i=0; i<v.size(); i++){
            for(int j=0; j<v[i].first; j++){
                ans+=v[i].second;
            }
        }
        return ans;
    }
};