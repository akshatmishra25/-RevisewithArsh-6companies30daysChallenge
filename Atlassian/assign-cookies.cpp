//Problem Link - https://leetcode.com/problems/assign-cookies/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        map<int, int> mp;
        for(int i=0; i<s.size(); i++){
            mp[s[i]]++;
        }
        int ans=0;
        for(int i=0; i<g.size(); i++){
            for(auto it: mp){
                if(it.first>=g[i] && it.second>0){
                    mp[it.first]--;
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};