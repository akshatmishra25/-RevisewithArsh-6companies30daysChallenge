// Problem Link - https://leetcode.com/problems/destroying-asteroids/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool asteroidsDestroyed(int m, vector<int>& asteroids) {
        long long mass = m;
        sort(asteroids.begin(), asteroids.end());
        for(int i=0; i<asteroids.size(); i++){
            if(mass>=asteroids[i]){
                mass+=asteroids[i];
            }
            else{
                return false;
            }
        }
        return true;
    }
};