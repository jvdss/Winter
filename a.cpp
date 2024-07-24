#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(int i = 0; i < n; ++i)
#define endl '\n'
#define int long long
#define pb push_back
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef vector<int> vi;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAX = 500+2;

int k;
vector<int> g[MAX];
int vis[MAX];
vector<int> tvis;
int d[MAX];
void bfs(vector<int>& r){
    queue<int> q;
    for(auto st : r){
        q.push(st);
        tvis[st] = 1;
        vis[st] = 0;
        d[st] = 0;
    }
    while(q.size()){
        auto u = q.front(); q.pop();
        for(auto v : g[u]){
            if(vis[v]) continue;
            d[v] = d[u] + 1;
            if(d[v] % k == 0){
                vis[v] = 1;
            }else{
                q.push(v);
            }
        }
    }
}
int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,m; cin >> n >> m;
    FOR(i,m){
        int a,b; cin >> a >> b; --a; --b;
        g[a].pb(b);
    }
    cin >> k;
    vector<int> raizes = {0};
    tvis = vector<int>(n,0);
    int r = 500;
    while(accumulate(all(tvis),0LL) != n and r--){
        bfs(raizes);
        raizes.clear();
        FOR(i,n){
            vis[i] = 0;
            if(d[i] != 0 and d[i]%k==0){
                raizes.pb(i);
            }
            d[i] = 0;
        }
    }
    
    
    cout << (tvis[n-1] ? "Sim" : "Nao") << endl;
    return 0;
}
