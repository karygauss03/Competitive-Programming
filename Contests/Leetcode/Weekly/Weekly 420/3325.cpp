class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int ans = 0;
        vector<int> freq(26, 0);
        for (int i = 0; i < s.size(); ++i) {
            fill(freq.begin(), freq.end(), 0);
            // freq[s[i] - 'a']++;
            for (int j = i; j < s.size(); ++j) {
                freq[s[j] - 'a']++;
                if (freq[s[j] - 'a'] == k) {
                    cout << i << ' ' << j << endl;
                    ans += (s.size() - j);
                    break;
                }
            }
        }
        return ans;
    }
};
