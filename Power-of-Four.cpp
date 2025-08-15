class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) return false;

        // Check if n is power of 2 (only one bit set)
        if ((n & (n - 1)) != 0) return false;

        // Check if that bit is in an even position (0, 2, 4, ...)
        // Mask for all 1s at even positions: 0x55555555
        return (n & 0x55555555) != 0;
    }
};
