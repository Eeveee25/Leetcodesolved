class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentSum = nums[0];
        int maxSum = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            // Extend the current subarray OR start new
            currentSum = max(nums[i], currentSum + nums[i]);
            
            // Update maxSum if needed
            maxSum = max(maxSum, currentSum);
        }
        
        return maxSum;
    }
};
