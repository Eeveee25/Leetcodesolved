class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);  // preallocate result vector
        int posIndex = 0;
        int negIndex = 1;

        for (int num : nums) {
            if (num > 0) {
                result[posIndex] = num;
                posIndex += 2;
            } else {
                result[negIndex] = num;
                negIndex += 2;
            }
        }

        return result;
    }
};

//two pointer approch 
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos;
        vector<int> neg;

        // Step 1: Separate positive and negative numbers
        for (int num : nums) {
            if (num > 0)
                pos.push_back(num);
            else
                neg.push_back(num);
        }

        // Step 2: Interleave pos and neg alternately
        vector<int> result;
        for (int i = 0; i < pos.size(); i++) {
            result.push_back(pos[i]);   // Add positive
            result.push_back(neg[i]);   // Add negative
        }

        return result;
    }
};
