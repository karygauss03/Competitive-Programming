#include<bits/stdc++.h>

class Solution {
private:
    vector<int> z_function(string s) {
        int n = s.size();
        int l = 0, r = 0;
        vector<int> z(n);
        for (int i = 1; i < n; ++i) {
            if (i < r) {
                z[i] = min(r - i, z[i - l]);
            }
            while (i + z[i] < n && s[z[i]] == s[z[i] + i]) {
                ++z[i];
            }
            if (i + z[i] >= r) {
                l = i;
                r = i + z[i];
            }
        }
        return z;
    }

public:
    int minStartingIndex(string s, string pattern) {
        int n = s.size(), p = pattern.size();
        vector<int> z = z_function(pattern + "#" + s);
        
        reverse(s.begin(), s.end());
        reverse(pattern.begin(), pattern.end());
        vector<int> rz = z_function(pattern + "#" + s);
        
        for(int i = 0; i <= n - p; ++i) {
            if (z[i + p + 1] + 1 + rz[n - i + 1] >= p) {
                return i;
            }
        }
        return -1;
    }
};
