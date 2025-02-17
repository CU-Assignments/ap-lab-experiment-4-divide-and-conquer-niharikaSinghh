class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        while (n) {
            n = n & (n - 1);  // Clears the least significant '1' bit
            count++;  // Increment the count of '1' bits
        }
        return count;
    }
};
