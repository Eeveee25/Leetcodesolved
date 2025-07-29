class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;

        int i = 0;  // Pointer to place the next unique number
        for (int j = 1; j < nums.size(); ++j) {
            if (nums[j] != nums[i]) {
                ++i;
                nums[i] = nums[j];  // Overwrite with next unique number
            }
        }
        return i + 1;  // Unique count = index + 1
    }
};
