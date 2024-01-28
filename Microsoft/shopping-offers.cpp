// Problem Link - https://leetcode.com/problems/shopping-offers/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // Store the minimum cost found for subproblems at a given state of needs.
    // Since each need is in [0,10], each need can be represented in 4 bits.
    // Since there are up to 6 needs, the entire needs state can be represented in 6*4=24 bits.
    // So, we can use a 32-bit integer mask as a key in the map to uniquely identify a needs state.
    unordered_map<int32_t, int> min_cost_for_state;

public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        // Make a bitmask of the current needs state
        int32_t mask = 0;
        for (int need : needs)
            mask = (mask | need) << 4;

        // If already cached result of this needs state, return that
        if (min_cost_for_state.count(mask))
            return min_cost_for_state[mask];

        // At this point, can either pick the regular item prices, or specials.
        // Start of by setting the minimum cost as that of using the regular prices for the remaining needed items.
        int min_cost = inner_product(price.begin(), price.end(), needs.begin(), 0);

        // Now test all the specials
        for (const auto &special_offer : special) {
            // Prune the search: if buying a special causes a price > current min, don't bother
            if (special_offer.back() > min_cost)
                continue;

            // Keep track of if come across negative needs, where we would buy more than needed
            int bought_too_much = false;
            // Temporarily apply the special to the needs vector, subtracting the purchased items from the needed items
            for (int i = 0; i < needs.size(); ++i) {
                needs[i] -= special_offer[i];
                // Stop if we've found a negative need, since that's invalid - undo the application
                if (needs[i] < 0) {
                    while (i >= 0) {
                        needs[i] += special_offer[i];
                        --i;
                    }
                    bought_too_much = true;
                    break;
                }
            }

            // Don't recur if we've found a negative need, since that is invalid
            if (bought_too_much) continue;

            // Update the current minimum cost if applying this special leads to a lower cost
            min_cost = min(min_cost, special_offer.back() + shoppingOffers(price, special, needs));

            // Undo the temporary application of the special to the needs vector
            for (int i = 0; i < needs.size(); ++i)
                needs[i] += special_offer[i];
        }

        // Cache this min cost value
        min_cost_for_state[mask] = min_cost;

        // Return the current minimum cost
        return min_cost;
    }
};