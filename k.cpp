#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(int i = 0; i < n; ++i)
#define endl '\n'

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct BIT{
    int n;
    vector<int> bit;
    BIT(int n_) : n(n_), bit(n+2){}
    void update(int i, ll x){
        for(i++; i <= n; i += i & -i) bit[i] += x;
    }
    ll pref(int i){
        ll ret = 0;
        for(i++; i; i -= i & -i) ret += bit[i];
        return ret;
    }
    ll query(int l, int r){
        return pref(r)- pref(l);
    }
};
int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    vector<int> v(n); FOR(i,n) cin >> v[i];
    int ans = 0;
    BIT ft(n+1);
    
    for(int i = 0; i < n; ++i){
        int x = v[i]-1;
        ans += ft.query(x,n-1);
        ft.update(x,1);
    }
    cout << ans << endl;
    return 0;
}
