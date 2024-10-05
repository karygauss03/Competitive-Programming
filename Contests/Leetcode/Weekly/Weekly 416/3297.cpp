class Solution {
private:
    unordered_map<char, int> word2Freq;
    unordered_map<char, int> subFreq;
public:
    long long validSubstringCount(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        for (auto &w : word2) {
            word2Freq[w]++;
        }

        int l = 0;
        long long ans = 0;
        char cur;
        int sz = 0, r;
        for (r = 0; r < n; ++r) {
            // Reduce the size of the window as much as we can having all word2 characters present in the window!
            while (sz == m && l <= r) {
                ans += (n - r + 1);
                cur = word1[l];
                subFreq[cur]--;
                if (word2Freq[cur] > 0 && word2Freq[cur] > subFreq[cur]) {
                    --sz;
                }
                ++l;
            }
            cur = word1[r];
            if (word2Freq[cur] > 0 && word2Freq[cur] > subFreq[cur]) {
                sz++;
            }
            subFreq[cur]++;
        }

        // Remaining characters
        while (l <= r && sz == m) {
            ans += (n - r + 1);
            cur = word1[l];
            subFreq[cur]--;
            if (word2Freq[cur] > 0 && word2Freq[cur] > subFreq[cur]) {
                --sz;
            }
            ++l;
        }

        return ans;
    }
};
