class Solution {
private:
    int ans = INT_MAX, n;
    void solve(vector<int>& a, int msk, int x, int k, int cur) {
        if (msk == (1 << n) - 1) {
            ans = min(ans, cur);
            return;
        }
        int time = 0;
        for (int i = 0; i < n; ++i) {
            if (msk & (1 << i)) continue; // added
            time = (a[i] + x - 1) / x;
            solve(a, msk | (1 << i), x + k, k, cur + time);
        }
    }
public:
    int findMinimumTime(vector<int>& strength, int k) {
        n = strength.size();
        sort(strength.begin(), strength.end());
        solve(strength, 0, 1, k, 0);
        return ans;
    }
};
