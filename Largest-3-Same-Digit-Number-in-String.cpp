class Solution {
public:
    string largestGoodInteger(string num) {
        string ans = "";
        
        for (int i = 0; i <= (int)num.size() - 3; i++) {
            // Take substring of length 3
            string sub = num.substr(i, 3);
            
            // Check if all characters are same
            if (sub[0] == sub[1] && sub[1] == sub[2]) {
                if (ans == "" || sub > ans) {
                    ans = sub;
                }
            }
        }
        
        return ans;
    }
};