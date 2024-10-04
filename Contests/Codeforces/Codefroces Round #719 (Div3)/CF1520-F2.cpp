//KARYGAUSS03
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vl ;
typedef pair<ll,ll> pl;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define max(a,b) (a>b ? a : b)
#define min(a,b) (a<b ? a : b)
#define KARYGAUSS03 ios::sync_with_stdio(0), cin.tie(0),cout.tie(0)
#define endl '\n'

const int MOD = (1e9)+7 ;
const int N = 2e5 + 5;
const double PI =4*atan(1);
const double eps = 1e-10;
const long long oo = 1e10;
const int K = 26;
const int M=(1e9)+7;
const ll inf = (1LL << 61) - 1;

void yes(){
    cout<<"YES\n";
}
void no(){
    cout<<"NO\n";
}

map<pair<int,int>,int> ma;

int check(int l , int r){
    if (ma.count({l,r}))
        return ma[{l,r}];
    cout<<"? "<<l<<' '<<r<<endl;
    cout.flush();
    int x;
    cin>>x;
    ma[{l,r}] = (r-l+1) - x;
    return ma[{l,r}];
}

vector<pair<int,int>> v;

int check_2 (int l, int r , int k){
    if (l==r) return l;
    int m = (l+r)/2;
    if (check(l,m)>=k){
        v.pb({l,m});
        return check_2 (l,m,k);
    }else {
        v.pb({m+1,r});
        return check_2 (m+1,r,k-check(l,m));
    }
}

int solve(int ans){
    cout<<"! "<<ans<<endl;
    cout.flush();
}


int main(){
    KARYGAUSS03;
    int t,n;
    cin>>n>>t;
    while(t--) {
        int k;
        cin>>k;
        v.clear();
        int ans = check_2(1,n,k);
        for (auto p : v){
            ma[{p.fi,p.se}] --;
        }
        solve(ans);
    }
	return 0;
}

