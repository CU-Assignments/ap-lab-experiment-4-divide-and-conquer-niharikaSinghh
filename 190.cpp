class Solution {
    public int reverseBits(int n) {
        int result = 0;
        for (int i = 0; i < 32; i++) {
            result <<= 1; // Shift result left by 1
            result |= (n & 1); // Get the last bit of n and add it to result
            n >>>= 1; // Use unsigned right shift
        }
        return result;
    }
    
    public static void main(String[] args) {
        Solution sol = new Solution();
        int n = Integer.parseUnsignedInt("00000010100101000001111010011100", 2); // Example input
        System.out.println(Integer.toBinaryString(sol.reverseBits(n)));
    }
}
