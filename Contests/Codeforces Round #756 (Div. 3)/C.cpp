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

const int MOD = (1e9)+7 ;
const int N = 1e5 + 5;
const double PI = acos(-1);
const double eps = 1e-10;
const long long oo = 1e10;
const ll inf = (1LL << 61) - 1;
void yes()
{
    cout<<"YES\n";
}
void no()
{
    cout<<"NO\n";
}


void solve()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0 ; i < n ; i++) cin >> a[i];
    if (a[0] != n && a[n - 1] != n) {
        cout << -1 << endl;
        return;
    }
    list<int> p;
    p.pb(n);
    if (a[0] == n){
        int i = 1, j = n - 1;
        while (i <= j){
            if (a[i] < a[j]){
                p.push_front(a[i]);
                i++;
            }
            else {
                p.push_back(a[j]);
                j--;
            }
        }
    }
    else {
        int i = 0, j = n - 2;
        while (i <= j){
            if (a[i] < a[j]){
                p.push_front(a[i]);
                i++;
            }
            else {
                p.push_back(a[j]);
                j--;
            }
        }
    }
    for (auto x : p){
        cout << x << ' ';
    }
    cout << endl;
}



int main()
{
    fastio;
    //freopen("input.txt","r", stdin);
    int t=1;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
