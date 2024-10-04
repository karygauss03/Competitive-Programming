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


void solve() {
    int n;
    string s;
    cin>>n>>s;
    ll ans = 0;
    int cnt = 0, start = -1 , cur = -1;
    bool first = 0;
    for (int i=0;i<n;i++) {
        if (s[i]=='*'){
            cnt++;
            if (!first){
                first = 1 ;
                start = i;
            }
            else {
                cur = i;
            }
        }
    }
    if (n==0 || n==1 || cnt == cur - start + 1){
        cout<<0<<endl;
        return ;
    }
    int left = 0;
    for (char c : s){
        if (c == '*'){
            left ++;
        }
        else {
            ans += min (left, cnt - left);
        }
    }
    cout<<ans<<endl;
}


int main(){
    KARYGAUSS03;
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
	return 0;
}

