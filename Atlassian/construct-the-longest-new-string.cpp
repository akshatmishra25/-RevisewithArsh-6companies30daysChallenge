//Problem Link - https://leetcode.com/problems/construct-the-longest-new-string/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestString(int x, int y, int z) {
       int mn = min(x, y);
       if(mn<x || mn<y){
           mn=4*mn+2;
       }
       else{
           mn=4*mn;
       }
       return mn+2*z; 
    }
};