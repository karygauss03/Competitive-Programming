#define ll long long
class Solution {
private:
    bool isPossible(ll t, int m, vector<int>& w) {
        ll h = 0;
        for (auto& ww : w) {
            ll l = 0, r = 1e6, mid;
            while (l <= r) {
                mid = l + (r - l) / 2;
                if (ww * (mid + 1) * mid / 2 <= t) {
                    l = mid + 1;
                }
                else {
                    r = mid - 1;
                }
            }
            h += r;
            if (h >= m) {
                return true;
            }
        }
        return false;
    }

public:
    long long minNumberOfSeconds(int  m , vector<int>& w) {
        ll left = 0, right = 1e18, mid, ans = 0;
        while (left <= right) {
            mid = (right - left) / 2 + left;
            if (isPossible(mid, m, w)){
                right = mid - 1;
                ans = mid;
            }
            else {
                left = mid + 1;
            }
        }
        return ans;
    }
};
