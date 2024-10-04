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
const int N = 1e5 + 5;
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




void solve(){
    int n, k;
    cin >> n >> k;
    int a[n];
    map<int, int> ma;
    for (int i = 0 ; i < n ; i++) {
        cin >> a[i];
        ma[a[i]]++;
    }
    vector<int> b;
    for (auto &x : ma){
        if (x.second >= k){
            b.pb(x.first);
        }
    }
    if (b.size() == 0){
        cout << -1 << endl;
        return;
    }

    sort(all(b));
    int mx = 0, l = b[0], r = b[0], tmp = b[0];
    int m = b.size();
    for (int i = 1 ; i < m ; i++){
        if (b[i] - 1 == b[i - 1]){
            if (b[i] - tmp > mx){
                l = tmp;
                r = b[i];
                mx = b[i] - tmp;
            }
        }
        else {
            tmp = b[i];
        }
    }
    cout << l << ' ' << r  << endl;
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
