class Solution {
public:
    int reversePairs(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        // Auxiliary function to merge and count reverse pairs
        return mergeSortAndCount(nums, 0, nums.size() - 1);
    }

private:
    // Merge sort function that counts reverse pairs while sorting
    int mergeSortAndCount(vector<int>& nums, int left, int right) {
        if (left >= right) return 0;
        
        int mid = left + (right - left) / 2;
        
        // Count reverse pairs in the left half, right half, and across both halves
        int count = mergeSortAndCount(nums, left, mid) + mergeSortAndCount(nums, mid + 1, right);
        
        // Count reverse pairs where one element is in the left half and one in the right half
        int j = mid + 1;
        for (int i = left; i <= mid; ++i) {
            while (j <= right && nums[i] > 2 * nums[j]) {
                ++j;
            }
            count += (j - (mid + 1));
        }
        
        // Merge the two halves (standard merge step)
        vector<int> temp;
        int i = left, k = mid + 1;
        while (i <= mid && k <= right) {
            if (nums[i] <= nums[k]) {
                temp.push_back(nums[i++]);
            } else {
                temp.push_back(nums[k++]);
            }
        }
        while (i <= mid) {
            temp.push_back(nums[i++]);
        }
        while (k <= right) {
            temp.push_back(nums[k++]);
        }
        for (int i = 0; i < temp.size(); ++i) {
            nums[left + i] = temp[i];
        }

        return count;
    }
};
