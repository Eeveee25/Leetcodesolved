class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0;

        for (int num : nums) {
            // First appearance: add it to ones
            // Second appearance: remove it from ones and add it to twos
            // Third appearance: remove it from twos
            ones = (ones ^ num) & ~twos;
            twos = (twos ^ num) & ~ones;
        }

        return ones;
    }
};
