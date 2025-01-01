class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        map<int, vector<int>> mp;
        int n = nums.size(), mn = 105;
        set<int> st;
        for (int i = 0; i < n; ++i) {
            mp[nums[i]].push_back(i);
            st.insert(nums[i]);
            mn = min(mn, nums[i]);
        }
        if (mn < k) return -1;
        int ans = 0;
        while (*st.rbegin() != k) {
            int cur = *st.rbegin();
            st.erase(cur);
            if (st.size() == 0) return ans + 1;
            int prev = *st.rbegin();
            cout << cur << endl;
            for (auto& i : mp[cur]) {
                mp[prev].push_back(i);
            }
            ++ans;
            mp.erase(cur);
        }
        return ans;
    }
};
