// Problem Link - https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/

#include<bits/stdc++.h>
using namespace std;



 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
public:
   void convert(TreeNode* node, int parent, unordered_map<int, vector<int>>& graph){
        if(node == nullptr) return;

        vector<int>& adjacencyList = graph[node->val];

        if(parent!=0) adjacencyList.push_back(parent);
        if(node->left != nullptr) adjacencyList.push_back(node->left->val);
        if(node->right != nullptr) adjacencyList.push_back(node->right->val);

        convert(node->left, node->val, graph);
        convert(node->right, node->val, graph);
    }
    int amountOfTime(TreeNode* root, int start) {
       unordered_map<int, vector<int>> graph;
       convert(root, 0, graph);
       queue<int> q;
       q.push(start);
       unordered_set<int> visited;
       visited.insert(start);
       int minute=0;
       while(!q.empty()){
           int s = q.size();
           while(s--){
               int cur_node = q.front();

               q.pop();
               for(int child : graph[cur_node]){
                   if(visited.find(child) == visited.end()){
                       visited.insert(child);
                       q.push(child);
                   }
               }
           }
           minute++;
       }
       return minute-1;         
    }
};