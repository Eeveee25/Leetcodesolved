class Solution {
public:
    int largestInteger(int num) {
        string s = to_string(num);
        vector<int> oddCount(10, 0), evenCount(10, 0);

        // Count frequency of each digit by parity
        for (char c : s) {
            int d = c - '0';
            if (d % 2 == 0) evenCount[d]++;
            else oddCount[d]++;
        }

        // Start from the largest digit (9 down to 0)
        string res = "";
        for (char c : s) {
            int d = c - '0';
            if (d % 2 == 0) {
                // Place the largest even digit available
                for (int i = 9; i >= 0; --i) {
                    if (evenCount[i] > 0) {
                        res += (i + '0');
                        evenCount[i]--;
                        break;
                    }
                }
            } else {
                // Place the largest odd digit available
                for (int i = 9; i >= 0; --i) {
                    if (oddCount[i] > 0) {
                        res += (i + '0');
                        oddCount[i]--;
                        break;
                    }
                }
            }
        }

        return stoi(res);
    }
};
