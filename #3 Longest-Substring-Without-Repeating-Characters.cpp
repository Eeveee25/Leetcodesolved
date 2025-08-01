class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lastSeen;
        int maxLength = 0;
        int left = 0;

        for (int right = 0; right < s.size(); ++right) {
            char c = s[right];

            // If 'c' was seen and its last position is within current window
            if (lastSeen.count(c) && lastSeen[c] >= left) {
                left = lastSeen[c] + 1;
            }

            lastSeen[c] = right;  // Update last seen index
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};
