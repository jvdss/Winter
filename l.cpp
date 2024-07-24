#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(int i = 0; i < n; ++i)
#define endl '\n'
// #define int long long
#define pb push_back
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef vector<int> vi;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAX = 2e5+2;


int n;
vi g[MAX], gi[MAX];
int vis[MAX];
stack<int> S;
int comp[MAX];

void dfs(int k){
    vis[k] = 1;
    for(int i = 0; i < (int)g[k].size(); i++)
        if(!vis[g[k][i]]) dfs(g[k][i]);

    S.push(k);
}

void scc(int k, int c){
    vis[k] = 1;
    comp[k] = c;
    for(int i = 0; i < (int)gi[k].size(); i++){
        if(!vis[gi[k][i]]) scc(gi[k][i], c);
    }
}

int kosaraju(){
    for(int i = 0; i < n; i++) vis[i] = 0;
    for(int i = 0; i < n; i++) if(!vis[i]) dfs(i);

    for(int i = 0; i < n; i++) vis[i] = 0;
    int nComp = 0;
    while(S.size()){
        int u = S.top();
        S.pop();
        if(!vis[u]) scc(u,nComp++);    
    }
    return nComp;
}

int in[MAX], out[MAX];
int t = 0;
void trav(int u, int visID ){
    
    in[u] = t++;
    for(auto v : gi[u]){
        trav(v, visID);
    }
    out[u] = t++;
}

bool anc(int a, int b){ 
    return in[a] <= in[b] and out[a] >= out[b];
}

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int m; cin >> n >> m;
    FOR(i,m){
        int a,b; cin >> a >> b;--a; --b;
        g[a].pb(b);
        gi[b].pb(a);
    }
    int ncomp = kosaraju();
    FOR(i,n) gi[i].clear();

    // indeices dos vertices da arvore vao ser os indices do componente
    vi ehRaiz(ncomp,1);
    FOR(i,n){
        int u = comp[i];
        for(auto j : g[i]){
            int v = comp[j]; // i -> j
            if( v != u){ // u < - v
                gi[v].pb(u);
                ehRaiz[u] = 0;
            }
        }
    }
    
    FOR(i,ncomp) vis[i] = 0;
    t = 0; int visID = 1;

    FOR(i,ncomp) if(ehRaiz[i]){
        trav(i, visID);
        visID++;
    }

    int q; cin >> q;
    while(q--){
        int a,b; cin >> a >> b;
        --a; --b;
        int ca = comp[a], cb = comp[b];
        cout << ( anc(cb, ca) ? "Sim" : "Nao") << endl;
    }
    return 0;
}
