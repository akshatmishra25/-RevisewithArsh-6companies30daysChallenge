// Problem link - https://leetcode.com/problems/wiggle-sort-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> temp1 = nums, temp2 = nums;
        sort(temp1.begin(), temp1.end());
        sort(temp2.rbegin(), temp2.rend());
        int j=(nums.size()-1)/2, k=0;
        for(int i=0; i<nums.size(); i+=2){
            nums[i]=temp1[j];
            if(i+1<nums.size()){
                nums[i+1]=temp2[k];
            }
            j--;
            k++;
        }
    }
};