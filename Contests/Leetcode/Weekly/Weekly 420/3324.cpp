class Solution {
public:
    vector<string> stringSequence(string target) {
        string cur = "";
        vector<string> ans;
        for (int i = 0; i < target.size(); ++i) {
            if (target[i] == 'a') {
                cur += 'a';
                ans.push_back(cur);
                continue;
            }
            else {
                cur += 'a';
                ans.push_back(cur);
                while (cur.back() != target[i]) {
                    cur.back()++;
                    ans.push_back(cur);
                }
            }
        }
        return ans;
    }
};
