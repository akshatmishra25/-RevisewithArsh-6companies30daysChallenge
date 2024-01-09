// Problem Link - https://leetcode.com/problems/circle-and-rectangle-overlapping/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkOverlap(int radius, int xcenter, int ycenter, int x1, int y1, int x2, int y2) {
        for(int i=x1; i<=x2; i++){
            for(int j=y1; j<=y2; j++){
                int x = (i-xcenter)*(i-xcenter);
                int y = (j-ycenter)*(j-ycenter);
                if(x+y<=(radius*radius)) return true;
            }
        }
        return false;
    }
};