class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSumCount;
        prefixSumCount[0] = 1;  // To count subarrays that start from index 0

        int count = 0;
        int currentSum = 0;

        for (int num : nums) {
            currentSum += num;

            // Check if there is a prefix sum that makes currentSum - k
            if (prefixSumCount.find(currentSum - k) != prefixSumCount.end()) {
                count += prefixSumCount[currentSum - k];
            }

            // Record current prefix sum in map
            prefixSumCount[currentSum]++;
        }

        return count;
    }
};
