class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};

        // Step 1: Sort intervals by their start time
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged;
        merged.push_back(intervals[0]);  // Start with the first interval

        // Step 2: Merge overlapping intervals
        for (int i = 1; i < intervals.size(); ++i) {
            vector<int>& last = merged.back();  // Last added interval
            vector<int>& current = intervals[i];

            if (current[0] <= last[1]) {
                // Overlap: extend the end time
                last[1] = max(last[1], current[1]);
            } else {
                // No overlap: add new interval
                merged.push_back(current);
            }
        }

        return merged;
    }
};
