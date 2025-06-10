class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;

        // Go through each bit position
        for (int i = 0; i < 32; i++) {
            int bitCount = 0;

            for (int num : nums) {
                // Check if the i-th bit is set in num
                if ((num >> i) & 1) {
                    bitCount++;
                }
            }

            // If the bitCount is not divisible by 3, that bit is set in the single number
            if (bitCount % 3 != 0) {
                result |= (1 << i);
            }
        }

        return result;
    }
};
