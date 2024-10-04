class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans = INT_MAX;
        for (auto &num : nums) {
            string str = to_string(num);
            num = 0;
            for (auto & c : str) {
                num += c - '0';
            }
            ans = min(num, ans);
        }
        return ans;
    }
};
