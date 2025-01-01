#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
 
template <typename T>
void tatawin(vector<T> &v, string name)
{
    cout << "-------" << endl;
    cout << name << " : ";
    for (auto &x : v)
    {
        cout << x << " ";
    }
    cout << endl;
    cout << "-------" << endl;
}
 
void solve()
{
    string s;
    cin >> s;
    int cpt = 0;
    ll sum = 0;
    int n = s.size();
    for (int i = 0; i < n; ++i)
    {
        cpt += 2 * (s[i] == '2');
        sum += (s[i] - '0');
    }
    ll distance = sum / 9;
    ll mod = sum % 9;
    if (!mod)
    {
        cout << "YES" << endl;
        return;
    }
    while (cpt--)
    {
        sum += 2;
        if ((sum) % 9 == 0)
        {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}