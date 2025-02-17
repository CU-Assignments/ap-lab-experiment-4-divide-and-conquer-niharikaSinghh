class Solution {
public:
    vector<int> beautifulArray(int n) {
        // Base case: if n is 1, the only possible beautiful array is [1]
        if (n == 1) {
            return {1};
        }
        
        // Recursively generate the beautiful array for odd numbers and even numbers
        vector<int> odd = beautifulArray((n + 1) / 2); // Generate array for odd numbers
        vector<int> even = beautifulArray(n / 2);      // Generate array for even numbers
        
        vector<int> result;
        
        // Add odd numbers first
        for (int num : odd) {
            result.push_back(2 * num - 1); // Map to actual odd numbers
        }
        
        // Add even numbers second
        for (int num : even) {
            result.push_back(2 * num); // Map to actual even numbers
        }
        
        return result;
    }
};
