class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        int count = 0;
        unordered_map<string, int> mp;
        for (auto& w: bannedWords) {
            mp[w] = 1;
        }
        for (auto &s : message) {
            if (mp[s]) {
                ++count;
            } 
            if (count == 2) {
                return true;
            }
        }
        return false;
    }
};
