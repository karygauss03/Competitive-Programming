//KARYGAUSS03
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<pair<int,int>> vp;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sz(x) ((int)(x).size())
#define max(a,b) (a>b ? a : b)
#define min(a,b) (a<b ? a : b)
#define fastio ios::sync_with_stdio(0), cin.tie(0),cout.tie(0)
#define endl '\n'

const int MOD = 1000000007;
const int N = 1e5 + 5;
const double PI = acos(-1);
const double eps = 1e-10;
const long long oo = 1e10;
const ll inf = (1LL << 61) - 1;

/*ll get_rand(ll l, ll r) {
    ll first_rand_value = (rand() * rand()) % MOD + MOD;
    ll second_rand_value = (rand() * rand()) % MOD + MOD;
    return (first_rand_value * second_rand_value) % (r - l + 1) + l;
}*/

void yes()
{
    cout<<"YES\n";
}
void no()
{
    cout<<"NO\n";
}
const int maxN = 5000005;
ll dp[5000005];
bool isPrime[5000005];
ll primes[5000005];
int n;

void solve()
{
    cin >> n;

    cout << dp[n] << endl;

}

void sieve(){
    isPrime[1] = false;
    for (int i = 2 ; i < maxN ; i++){
        isPrime[i] = true;
    }
    for (int i = 2 ; i*i < maxN ; i++){
        if (isPrime[i]){
            for (int j = i * i ; j < maxN ; j += i){
                isPrime[j] = false;
            }
        }
    }
}

void prep(){
    primes[0] = 0;
    for (int i = 1 ; i < maxN ; i++){
        primes[i] = primes[i - 1] + (isPrime[i] ? 1 : 0);
        //primes[i] %= MOD;
    }
    dp[1] = 1;
    for (int i = 2 ; i < maxN ; i++){
        dp[i] = ((primes[i] + 1)) * dp[i - 1];
        dp[i] %= MOD;
    }
}

int main()
{
    fastio;
    //freopen("input.txt","r", stdin);
    int t=1;
    cin>>t;
    sieve();
    prep();
    while(t--)
    {
        solve();
    }
    return 0;
}
