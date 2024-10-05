#define ll long long
class Solution {
public:
    long long minNumberOfSeconds(int  m , vector<int>& w) {
        priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<tuple<ll, ll, ll>>> pq;
        for(int i=0;i<w.size();i++){
            pq.push({w[i],w[i],1});
        }
        ll ans=0;
        while(m>0){
            auto t = pq.top();
            pq.pop();
            ll a = get<0>(t);
            ll b = get<1>(t);
            ll c = get<2>(t);
            ans=max(ans,a);
            m-=1;
            pq.push({a+b*(c+1),b,c+1});
        }
        return ans;
    }
};
