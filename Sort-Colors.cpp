class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size() - 1;
        
        while (mid <= high) {
            if (nums[mid] == 0) {
                // swap nums[low] and nums[mid], move low and mid forward
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            } else if (nums[mid] == 1) {
                // white → just move mid forward
                mid++;
            } else {
                // nums[mid] == 2 → swap with high, move high back
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};
