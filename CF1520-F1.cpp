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



int check(int l , int r){
    cout<<"? "<<l<<' '<<r<<endl;
    cout.flush();
    int x;
    cin>>x;
    return x;
}


int solve (int ans){
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
        int l=1, r=n;
        int ans = 0;
        while (l<=r){
            int m = (l+r)/2;
            int x = check (1,m);
            int y = m-x;
            if (y>=k){
                ans = m;
                r = m-1;
            }
            else {
                l=m+1;
            }
        }
        solve(ans);
    }
	return 0;
}

