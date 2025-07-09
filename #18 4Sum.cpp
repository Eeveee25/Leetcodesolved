class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for(int a = 0; a < n - 3; a++){
            if( a > 0 && nums[a] == nums[a-1]) continue;
                for(int b = a + 1; b< n-2; b++){
                    if(b > a+1 && nums[b] == nums[b-1]) continue;

                    if((long long) nums[a] + nums[b] + nums[b+1] + nums[b+2] > target) break;
                    if((long long) nums[a] + nums[b] + nums[n-1] + nums[n-2] < target) continue;

                    int c = b+1, d = n-1;
                    while(c <d){
                        long long sum=(long long) nums[a] + nums[b] +nums[c]+ nums[d];
                        
                        if(sum == target){
                            res.push_back({nums[a], nums[b], nums[c], nums[d]});
                            
                            while(c<d && nums[c] == nums[c+1]) c++;
                            while(c<d && nums[d] == nums[d-1]) d--;
                            c++;
                            d--;
                        }else if(sum < target){
                            c++;
                        }else{
                            d--;
                        }
                    }
                }
        }
        return res;
    }
};
