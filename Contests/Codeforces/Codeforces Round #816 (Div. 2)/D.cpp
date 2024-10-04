#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define show(x) cout << #x << " = " << x << endl
#define max(x, y) ((x) > (y) ? (x) : (y))
#define min(x, y) ((x) < (y) ? (x) : (y))
const int N = 2e5 + 3;


void solve(){
    	int n, q;
	cin >> n >> q;

	vector<pair<int, int>> v[n+1];

	while(q--){

		int i, j, x;
		cin >> i >> j >> x;

		v[i].emplace_back(j, x);
		v[j].emplace_back(i, x);
	}

	vector<int> a(n+1, INT_MAX);
	for(int i=1; i<=n; i++){

		for(auto p : v[i])
			a[i] &= p.se;

		if(v[i].empty())
			a[i] = 0;
	}

	if(n == 1){
		cout << a[1];
		exit(0);
	}

	for(int i=1; i<=n; i++){

		int y = a[i];
		for(auto p : v[i]){
			y &= a[p.fi];
			if(p.fi == i) y = 0;
		}

		a[i] ^= y;
		cout << a[i] << ' ';
	}
}


int main(){
    fastio
    int t = 1;
    //cin >> t;
    while (t--){
        solve();
    }
    return 0;
}
