class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        string prefix = strs[0];  // Start by assuming the first string is the prefix

        for (int i = 1; i < strs.size(); ++i) {
            int j = 0;
            // Compare prefix with current string character by character
            while (j < prefix.size() && j < strs[i].size() && prefix[j] == strs[i][j]) {
                ++j;
            }
            // Cut the prefix to the matched portion
            prefix = prefix.substr(0, j);

            // If prefix becomes empty, return early
            if (prefix.empty()) return "";
        }

        return prefix;
    }
};
