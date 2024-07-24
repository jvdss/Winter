#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(int i = 0; i < n; ++i)
#define endl '\n'
#define int long long
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef vector<int> vi;
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
        return pref(r)- pref(l-1);
    }
};

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n, preco; cin >> n >> preco;
    vi numbers, a(n);
    FOR(i,n){
        cin >> a[i];
        numbers.push_back(a[i]/preco);
    }
    sort(all(numbers));
    numbers.erase(unique(all(numbers)), numbers.end());
    BIT ft(numbers.size()+1);
    vi ans(n);
    for(int i = 0; i < n; ++i){
        int id = lower_bound(all(numbers), a[i]/preco) - numbers.begin();
        ans[i]= ft.query(id+1, numbers.size()-1);
        ft.update(id, 1);
    }
    for(auto x : ans){
        cout << x << " ";
    }cout << endl;
    return 0;
}
