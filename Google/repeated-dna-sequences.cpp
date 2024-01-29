// Problem Link - https://leetcode.com/problems/repeated-dna-sequences/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<string, int> mp;
        vector<string> ans;
        if(s.size()<10) return ans;
        for(int i=0; i<=s.size()-10; i++){
            string str = s.substr(i, 10);
            mp[str]++;
        }
        
        if(mp.size()>0){
        for(auto it : mp){
            if(it.second>1){
                ans.push_back(it.first);
            }
        }}
        return ans;
    }
};