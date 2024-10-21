class Graph{
public:
    vector<vector<int>> adj;
    int n;
    Graph(vector<int>& par) {
        n = par.size();
        adj.resize(n);
        for (int i = 1; i < par.size(); ++i) {
            adj[par[i]].push_back(i);
        }
        for (auto& v : adj) {
            sort(v.begin(), v.end());
        }
    }

    void dfs(int x, const string& s, string& cur, vector<pair<int, int>>& range) {
        int idx = cur.size();
        for (auto& child: adj[x]) {
            dfs(child, s, cur, range);
        }
        cur += s[x];
        range[x] = make_pair(idx, (int)(cur.size() - 1));
    }
};

class Solution {
private:
    vector<int> manacher_odd(string s) {
        int n = s.size();
        s = "$" + s + "^";
        vector<int> p(n + 2);
        int l = 1, r = 1;
        for(int i = 1; i <= n; i++) {
            p[i] = max(0, min(r - i, p[l + (r - i)]));
            while(s[i - p[i]] == s[i + p[i]]) {
                p[i]++;
            }
            if(i + p[i] > r) {
                l = i - p[i], r = i + p[i];
            }
        }
        return vector<int>(begin(p) + 1, end(p) - 1);
    }
    
    vector<int> manacher(string s) {
        string t;
        for(auto c: s) {
            t += string("#") + c;
        }
        auto res = manacher_odd(t + "#");
        return vector<int>(begin(res) + 1, end(res) - 1);
    }
public:
    vector<bool> findAnswer(vector<int>& parent, string s) {
        vector<bool> ans(parent.size(), false);
        Graph graph = Graph(parent);
        vector<pair<int, int>> range(parent.size());
        string cur = "";
        graph.dfs(0, s, cur, range);
        
        vector<int> arr = manacher(cur);
        
        for (int i = 0; i < parent.size(); ++i) {
            auto& [a, b] = range[i];
            int len = b - a + 1;
            if (arr[(a + b)] >= len) {
                ans[i] = true;
            }
        }
        return ans;
    }
};
