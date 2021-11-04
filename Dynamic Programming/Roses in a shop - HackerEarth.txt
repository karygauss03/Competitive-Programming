#include <bits/stdc++.h>

using namespace std;

long long smell[200000 + 1];
int n;
int dp[200001][2];

long long make (long long pos, long long k){
	long long p = 1, q = 1;
	if (dp[pos][k] != -1){
		return dp[pos][k];
	}
	if (smell[pos + 1] > smell[pos] && pos != n - 1){
		p = make(pos + 1, k) + 1;
	}
	if (smell[pos + 2] > smell[pos] && pos != n - 1 && k == 0){
		q = make(pos + 2, k + 1) + 1;
	}
	return dp[pos][k] = max(p, q);
}

int main() {
	cin >> n;
	for (int i = 0 ; i < n ; i++){
		cin >> smell[i];
	}
	long long ans = -1;
	memset(dp, -1, sizeof(dp));
	for (int i = 0 ; i < n ; i++)
	{
		long long choice = make(i, 0);
		ans = max(ans, choice);
	}
	cout << ans << endl;
}