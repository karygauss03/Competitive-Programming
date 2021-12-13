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

int a, b, cnt, row[8];

// row[c] = r means that the queen in the row R is located at the column c

bool check(int r, int c){
    for (int i = 0 ; i < c ; i++){
        if ((row[i] == r)||(abs(row[i] - r) == abs(i - c))){
            return false;
        }
    }
    return true;
}

void solve(int c)
{
    if (c == 8 && row[b] == a){
        printf("%2d      %d", ++cnt, row[0] + 1);
                for(int j = 1; j < 8; j++)
                    printf(" %d", row[j] + 1);
                printf("\n");
        return;
    }
    for (int r = 0 ; r < 8 ; r++){
        if (check(r, c)){
            row[c] = r;
            solve(c + 1);
        }
    }
}


int main()
{
    fastio;
    freopen("input.txt","r", stdin);
    int t=1;
    cin>>t;
    while(t--)
    {
        memset(row, 0, sizeof(row));
        cnt = 0;
        cin >> a >> b;
        a--;
        b--;
        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");
        solve(0);
        //if (t) cout << endl;
    }
    return 0;
}
