//KARYGAUSS03
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vl ;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

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

const int MOD = (1e9)+7 ;
const int N = 1e5 + 5;
const double PI = acos(-1);
const double eps = 1e-10;
const long long oo = 1e10;
const int K = 26;
const int M=(1e9)+7;
const ll inf = (1LL << 61) - 1;
const int INF = 10000;
void yes()
{
    cout<<"YES\n";
}
void no()
{
    cout<<"NO\n";
}


ll n,m,x,y,k,dx, dy;
vector<pair<ll,ll>> vect;

bool isValid(ll x, ll y){
    if (x > 0 && x <= n && y > 0 && y <= m){
        return true;
    }
    return false;
}

void solve(){
    cin >> n >> m;
    cin >> x >> y;
    cin >> k;
    for (int i = 0 ; i < k ; i++){
        cin >> dx >> dy;
        vect.pb(mp(dx,dy));
    }
    ll ans = 0;
    for (auto p : vect){
        dx = p.fi;
        dy = p.se;
        for (ll i = 1200000000 ; i > 0 ; i /= 2){
            while(isValid(x + dx * i, y + dy * i)){
                x += dx * i;
                y += dy * i;
                ans += i;
                //cout << "Update " << x << ' ' << y << '#' << ans << endl;
            }
        }
    }
    cout << ans;
}

int main()
{
    fastio;
    int t=1;
    //cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
