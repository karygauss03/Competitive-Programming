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

const int MOD = (1e9)+7 ;
const int N = int(1e6) + 69 ;
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

//DECARATIONS
ll t,n;
vector<pair<int,int>> occ [5000005];
int a[5000005];
void solve (){
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];

    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n-i;j++){
            int sum=a[j]+a[j+i];
            for (auto x : occ[sum]){
                if (x.fi!=j && x.se!=i+j && x.fi!=i+j && x.se!=j){
                    yes();
                    cout<<x.fi<<" "<<x.se<<" "<<j<<" "<<i+j;
                    return ;
                }
            }
            occ [sum].pb({j,j+i});
        }
    }


    //TLE 73
    /*for (int i=0;i<n;i++){
        for (int j=i+1;j<n;j++){
            int x=a[i]+a[j];
            if (ma.find(x) == ma.end()){
                ma[x]={i,j};
            }
            else {

                pair<int,int> p = ma[x];
                if (i==p.fi  || i==p.se || j==p.fi || j==p.se){
                    continue;
                }
                yes();
                cout<<i<<" "<<j<<" "<<p.fi<<" "<<p.se<<endl;
                return;
            }
        }
    }*/
    no();
}

int main(){
    KARYGAUSS03;
    t=1;
    while(t--) {
        solve();
    }
	return 0;
}
 