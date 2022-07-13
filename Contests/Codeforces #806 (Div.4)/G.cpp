#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define rep(i, x) for (int i = 0; i < (int)(x); i++)
#define rep1(i, x) for (int i = 1; i <= (int)(x); i++)
#define show(x) cout << #x << " = " << x << endl
#define max(x, y) ((x) > (y) ? (x) : (y))
#define min(x, y) ((x) < (y) ? (x) : (y))
const int N = 1e5 + 3;

int n , k;
int v[N];
int dp[N][32];

int doDP(int idx , int km){
 
    if(idx == n)return 0 ;
    if(km == 32)km = 31 ;
 
    int &ret = dp[idx][km];
    if(~ret)
        return ret ;
 
 
 
    int add = v[idx];
    for(int i = 0 ; i < km  && add; i ++)add /= 2 ;
 
 
    ret = doDP(idx + 1 , km + 1 ) + add / 2;
    ret = max(ret , doDP(idx + 1 , km) +add - k);
 
    return ret ;
}

void solve(){
    cin >> n >> k;
    for (int i = 0 ; i <= n ; i++){
	for (int j = 0 ; j < 32 ; j++){
		dp[i][j] = -1;
	}
    }
    for (int i = 0 ; i < n ; i++) cin >> v[i];
    cout << doDP(0, 0) << endl;
}

int main(){
    fastio
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}
