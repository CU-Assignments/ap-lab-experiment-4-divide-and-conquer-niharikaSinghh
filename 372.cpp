class Solution {
public:
    // Helper function to compute a^b % mod using recursion
    int modPow(int a, long long b, int mod) {
        int res = 1;
        a = a % mod;  // In case a is larger than mod
        while (b > 0) {
            if (b % 2 == 1) {
                res = (res * a) % mod;
            }
            a = (a * a) % mod;
            b /= 2;
        }
        return res;
    }
    
    int superPow(int a, vector<int>& b) {
        int mod = 1337;
        a = a % mod;  // In case a is larger than mod
        
        // Convert the array b to a single large number mod (not needed directly)
        long long b_val = 0;
        for (int i = 0; i < b.size(); ++i) {
            b_val = (b_val * 10 + b[i]) % (mod - 1);  // Using Euler's theorem
        }

        // Use modular exponentiation with b_val as the exponent
        return modPow(a, b_val, mod);
    }
};
