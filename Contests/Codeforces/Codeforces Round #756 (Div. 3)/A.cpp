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
    string s;
    cin >> s;
    int n = s.size();
    if ((s[n - 1] - '0')%2 == 0){
        cout << 0 << endl;
        return;
    }
    if ((s[0] - '0') % 2 == 0){
        cout << 1 << endl;
        return;
    }
    for (auto x : s){
            if ((x - '0')%2 == 0){
                cout << 2 << endl;
                return;
            }
    }
    cout <<-1<<endl;
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
