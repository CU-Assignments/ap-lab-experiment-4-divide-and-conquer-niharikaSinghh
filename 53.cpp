class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // Initialize variables
        int maxSum = nums[0];  // To store the maximum sum found so far
        int currentSum = nums[0];  // To store the current subarray sum
        
        // Iterate through the array starting from index 1
        for (int i = 1; i < nums.size(); i++) {
            // Update the current subarray sum
            currentSum = max(nums[i], currentSum + nums[i]);
            
            // Update the maximum sum found so far
            maxSum = max(maxSum, currentSum);
        }
        
        return maxSum;
    }
};
