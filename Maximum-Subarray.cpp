class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxval=nums[0];
        int sum=0;
        for(int i=0;i<nums.size();i++){
            
            if(sum<0){
                sum=0;
            }
            sum=sum+nums[i];
            maxval=max(maxval,sum);

        }
        return maxval;
        
    }
};