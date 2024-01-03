// Problem Link - https://leetcode.com/problems/find-consecutive-integers-from-a-data-stream/

#include<bits/stdc++.h>
using namespace std;

class DataStream {
public:
    int val;
    int req;
    int count = 0;
    DataStream(int value, int k) {
        val = value;
        req = k; 
    }
    
    bool consec(int num) {
        if(num == val){
            count++;
        } 
        else{
            count=0;
        }
        return count>=req;
    }
};



/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream obj = new DataStream(value, k);
 * boolean param_1 = obj.consec(num);
 */

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */