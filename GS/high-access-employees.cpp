// Problem Link - https://leetcode.com/problems/high-access-employees/submissions/1134814932/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
       unordered_map<string, vector<int>> mp;
       vector<string> ans;
       for(int i=0; i<access_times.size(); i++){
           int n=0;
           for(int j=0; j<access_times[i][1].size(); j++){
               int x=(access_times[i][1][j]-'0');
               n=(n*10)+x;
           }
           mp[access_times[i][0]].push_back(n);
       }
       for(auto it: mp){
           vector<int> v;
           v=it.second;
           if(v.size()>=3){
            sort(v.begin(), v.end());
            for(int i=0; i<v.size()-2; i++){
                if((v[i+2]-v[i])<100){
                    ans.push_back(it.first);
                    break;
                }
            }
           }
       }
       return ans;
    }
};