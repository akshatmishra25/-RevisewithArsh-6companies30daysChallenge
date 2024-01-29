// Problem Link - https://leetcode.com/problems/count-words-obtained-after-adding-a-letter/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        
        unordered_set<string> startSet;
        
		// Store all startWords in set
        for(auto word : startWords) {
			// Sort word and then store it in set
            sort(word.begin(), word.end()); 
            startSet.insert(word);
        }
        
		// Count of number of targetWords
		// than can be obtained from startWords
		// using APPEND and REARRANGE operation
        int count = 0;
        
        for(auto word : targetWords) {
			// Sort word so that we can handle REARRANGE case
            sort(word.begin(), word.end());
            
            for(int i=0; i<word.size(); i++) {
				// Skip one character from word
                string sortedWord = word.substr(0, i) + word.substr(i+1);
				// Find if new word with skipped character is present in set
                if(startSet.find(sortedWord) != startSet.end()) {
					// If yes, then increment count and break
                    count++;
                    break;
                }
            }
        }
        return count;
    }
};