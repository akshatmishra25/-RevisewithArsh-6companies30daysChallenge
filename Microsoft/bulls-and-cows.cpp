// Problem Link - https://leetcode.com/problems/bulls-and-cows/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> mp;
        int bull = 0;
        for(int i=0; i<secret.size(); i++){
            if(guess[i]==secret[i]){
                bull++;
            }
            else {
                mp[secret[i]]++;
            }
        }
         int cow = 0;
        for(int i=0; i<guess.size(); i++){
             
             if(guess[i]!=secret[i] && mp.find(guess[i])!=mp.end()){
                if(mp[guess[i]]>0){
                    cow++;
                    mp[guess[i]]--;
                }
            }
        }
        string ans = to_string(bull);
        ans+='A';
        ans=ans+(to_string(cow));
        ans+='B';
        return ans;

    }
};