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
const int N = 2e5 + 5;
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

int dx[]= {1,1,-1,-1,2,2,-2,-2};
int dy[] = {2,-2,2,-2,1,-1,1,-1};
int d[10][10];

bool check(int r, int c){
    return(r >= 0 & c >= 0 && r <8 && c <8);
}

int bfs(int sr, int sc, int dr, int dc){
    memset(d, -1, sizeof(d));
    d[sr][sc] = 0;
    queue<int> q;
    q.push(sr);
    q.push(sc);
    while(!q.empty()){
        int r = q.front() ; q.pop();
        int c = q.front() ; q.pop();
        if (r == dr && c == dc){
            return d[r][c];
        }
        for (int i = 0 ; i < 8 ; i++){
            int nr = r + dx[i];
            int nc = c + dy[i];
            if (!check(nr,nc)) continue;
            if (d[nr][nc] == -1){
                d[nr][nc] = d[r][c] + 1;
                q.push(nr);
                q.push(nc);
            }
        }
    }
    return -1;
}

void solve(){
    string A,B;
    while(cin >> A >> B ){
        int ans = bfs(A[1] - '1', A[0] - 'a', B[1] - '1', B[0] - 'a');
        cout << "To get from " << A << " to " << B << " takes " << ans << " knight moves.\n";
    }
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
