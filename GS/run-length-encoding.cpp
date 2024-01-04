//Problem Link - https://www.geeksforgeeks.org/problems/run-length-encoding/1

#include<bits/stdc++.h>
using namespace std;

string encode(string s)
{     
  int flag = 0;
  int cur = 1;
  char curr = s[0];
  string ans = "";
  for(int i=1; i<s.size(); i++){
      if(flag==1){
          if(s[i]==s[i-1]){
            cur++;  
          }
          else{
              ans+=curr;
              ans+=('0'+cur);
              cur=1;
              curr=s[i];
              flag=0;
          }
      }
      else{
          if(s[i]==s[i-1]){
              cur++;
              flag=1;
          }
          else{
              ans+=curr;
              ans+=('0'+cur);
              curr=s[i];
          }
      }
  }
  ans+=curr;
  ans+=('0'+cur);
  return ans;
}     