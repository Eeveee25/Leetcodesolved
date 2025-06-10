class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int missing = nums.size();  // Start with n
        for (int i = 0; i < nums.size(); i++) {
            missing ^= i ^ nums[i];
            //XOR approach used here 
            //a ^ a = 0
            //a ^ 0 = a
        }
        return missing;
    }
};
