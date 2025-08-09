class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<long long, long long> cnt;
        long long minCost = LLONG_MAX;
        int n = basket1.size();

        for (int i = 0; i < n; ++i) {
            cnt[basket1[i]]++;
            cnt[basket2[i]]--;
            minCost = min(minCost, (long long)min(basket1[i], basket2[i]));
        }

        vector<long long> extras;
        for (auto& [fruit, diff] : cnt) {
            if (diff % 2 != 0) return -1;
            for (int i = 0; i < abs(diff) / 2; ++i) {
                extras.push_back(fruit);
            }
        }

        sort(extras.begin(), extras.end());
        long long totalCost = 0;
        for (int i = 0; i < extras.size() / 2; ++i) {
            totalCost += min(extras[i], 2LL * minCost);
        }

        return totalCost;
    }
};
