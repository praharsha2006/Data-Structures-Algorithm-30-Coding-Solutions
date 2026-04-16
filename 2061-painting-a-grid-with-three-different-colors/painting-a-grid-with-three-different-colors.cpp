class Solution {
public:
    int colorTheGrid(int m, int n) {
        const int MOD = 1e9 + 7;
        vector<vector<int>> states;
        vector<int> curr(m);

        generateStates(0, m, curr, states);

        int sz = states.size();
        vector<vector<int>> adj(sz);

        for (int i = 0; i < sz; i++) {
            for (int j = 0; j < sz; j++) {
                if (isCompatible(states[i], states[j])) {
                    adj[i].push_back(j);
                }
            }
        }

        vector<long long> dp(sz, 1), newDp(sz);

        for (int col = 1; col < n; col++) {
            fill(newDp.begin(), newDp.end(), 0);

            for (int i = 0; i < sz; i++) {
                for (int j : adj[i]) {
                    newDp[j] = (newDp[j] + dp[i]) % MOD;
                }
            }

            dp = newDp;
        }

        long long ans = 0;
        for (long long x : dp) ans = (ans + x) % MOD;

        return ans;
    }

    void generateStates(int idx, int m, vector<int>& curr, vector<vector<int>>& states) {
        if (idx == m) {
            states.push_back(curr);
            return;
        }

        for (int color = 0; color < 3; color++) {
            if (idx > 0 && curr[idx - 1] == color) continue;
            curr[idx] = color;
            generateStates(idx + 1, m, curr, states);
        }
    }

    bool isCompatible(vector<int>& a, vector<int>& b) {
        for (int i = 0; i < a.size(); i++) {
            if (a[i] == b[i]) return false;
        }
        return true;
    }
};