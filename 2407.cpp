#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums, int k) {
        unordered_map<int, int> dp;  // dp[x] will store the length of the longest subsequence ending with x
        int result = 0;

        for (int num : nums) {
            int maxLen = 0;
            // Check for possible subsequences ending with values in the range [num - k, num - 1]
            for (int i = num - k; i < num; ++i) {
                if (dp.find(i) != dp.end()) {
                    maxLen = max(maxLen, dp[i]);
                }
            }
            // The subsequence ending with 'num' would be 1 + the max length from previous valid subsequences
            dp[num] = max(dp[num], maxLen + 1);
            result = max(result, dp[num]);
        }

        return result;
    }
};
