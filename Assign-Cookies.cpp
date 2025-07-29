class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end()); // sort greed levels
        sort(s.begin(), s.end()); // sort cookie sizes

        int child = 0, cookie = 0;

        while (child < g.size() && cookie < s.size()) {
            if (s[cookie] >= g[child]) {
                // Cookie satisfies this child
                child++;
            }
            // Move to next cookie either way
            cookie++;
        }

        return child; // Number of content children
    }
};
