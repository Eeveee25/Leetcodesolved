class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int a =nums.size();
        unordered_map<int,int>m;
        m.reserve(a);
        for(int i=0;i<a;i++)
        {
            int complement=target-nums[i];
            if(m.count(complement))
            {
                return{m[complement],i};
            }
            m[nums[i]]=i;
        }
        return{};
    }
};

