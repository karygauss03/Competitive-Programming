#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define show(x) cout << #x << " = " << x << endl
#define max(x, y) ((x) > (y) ? (x) : (y))
#define min(x, y) ((x) < (y) ? (x) : (y))
const int N = 2e5 + 3;


void solve(int tc){
    int n, d[3];
        cin>>n>>d[0]>>d[1]>>d[2];
        bool valid = true;

        for (int i = 0; i < 3; ++i) {
            if ((d[i] + d[(i+1)%3] - d[(i+2)%3]) % 2 != 0) {
                valid = false;
                break;
            }
        }

        int dist[3];
        for (int i = 0; i < 3; ++i) {
            dist[(i+1)%3] = (d[i]+d[(i+1)%3]-d[(i+2)%3])/2;
            if (dist[(i+1)%3] < 0) valid = false;
        }

        if (dist[0]+dist[1]+dist[2]+1 > n) valid = false;

        if (!valid) {
            cout<<"NO"<<"\n";
            return;
        }

        cout<<"YES"<<"\n";
        int root = 4;
        int val = 5;
        for (int i = 0; i < 3; ++i) {
            if (dist[i] == 0) {
                root = i+1;
                val = 4;
                break;
            }
        }

        for (int v = 0; v < 3; ++v) {
            if (dist[v] == 1) cout<<v+1<<" "<<root<<"\n";
            else if (dist[v] > 1) {
                cout<<v+1<<" "<<val<<"\n";
                for (int i = 0; i < dist[v]-2; ++i) {
                   cout<<val<<" "<<val+1<<"\n";
                   val++;
                }
                cout<<val<<" "<<root<<"\n";
                val++;
            }
        }

        for (int i = 0; i < n-1-dist[0]-dist[1]-dist[2]; ++i) {
            if (i == 0) cout<<1<<" "<<val<<"\n";
            else {
                cout<<val<<" "<<val+1<<"\n";
                val++;
            }
        }
}


int main(){
    fastio
    int t = 1;
    cin >> t;
    int tc = 1;
    while (t--){
        solve(tc);
        tc++;
    }
    return 0;
}
