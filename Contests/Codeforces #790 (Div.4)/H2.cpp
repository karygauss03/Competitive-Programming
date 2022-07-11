//KARYGAUSS03

//------------------------------------------------------------------------------
             /////////        ./////          ((((((          ,#####
            ///////////  ******////////((,  ((((((((((      ##########
            ///////////********////////((( ((((((((((((    ############
           /////////////*****        //(( (((((((((#%%%    #############
          ///////////////**               ((((((((##%%%%  ##############
         ///////  ********               ((((((((###%%%%%################
        ///////  //********             (((((((( ###%%%%######### ########
       /////////////********           (((((((((  ###%%%########  #########
      ///////////////**********/  ,////((((((((    #%%%########    ########,
     ///////////       ********////////(((((##      %%########      ########
    ////////               ****////////((####       ,########        ########
//------------------------------------------------------------------------------

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sz(x) ((int)(x).size())
#define max(a,b) (a>b ? a : b)
#define min(a,b) (a<b ? a : b)
#define fastio ios::sync_with_stdio(0), cin.tie(0),cout.tie(0)
#define endl '\n'

const int MOD = 1000000007;
const int N = 5e5 + 9;
const double PI = acos(-1);
const double eps = 1e-10;
const long long oo = 1e10;
const ll inf = (1LL << 61) - 1;


const int dx[] = {-1, 0, 1, 0};
const int dy[] = { 0, 1, 0,-1};

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

int a[N],tr[N];
int sum(int x)
{
	int res = 0;
	for (; x ; x -= (x&-x)) res += tr[x];
	return res;
}
void add(int x,int n)
{
	for (; x <= n ; x += (x&-x)) tr[x]++;
}

void solve(){
    int n;
    cin >> n;
    memset(tr, 0, sizeof tr);
    for (int i = 1 ; i <= n ; i++) cin >> a[i];
    ll ans = 0;
    for (int i = n ; i ; i--){
        ans += sum(a[i]);
        add(a[i], n);
    }

    cout << ans << endl;
}


signed main()
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
