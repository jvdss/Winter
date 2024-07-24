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
const int MAX = 35+2;

int n;
vector<int> g[MAX];
int vis[MAX];
int parent[MAX];
int tail = -1;
stack<int> st;
vector<int> path;
bool deu;
void dfs(int u ){
    st.push(u);
    vis[u] = 1;
    int seen = 0;
    bool has_zero = false;
    for(auto v : g[u]) {
        if( v == 0) has_zero = 1;
        if( vis[v] == 1 ){
            continue;
        }
        
        dfs(v);
        if(deu) return;
    }
    if(st.size() == n and has_zero){
        deu = true;
        while(st.size()){
            path.pb(st.top());
            st.pop();
        }
    }
    if(deu) return;
    vis[u] == 0;
    if(st.size())st.pop();
}
int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int x; cin >> n >> x;
    vector<string> v(n);
    for(int i = 0; i < n; ++i){
        cin >> v[i];
    }
    if( n == 1){
        cout << v[0] << " -> " << v[0] << endl;return 0;
    }
    auto getDif = [&](string& a, string& b){
        int d = 0;
        for(int i = 0; i < a.size(); ++i){
            d += (a[i] != b[i]);
        }return d;
    };
    for(int i = 0; i < n; ++i){
        for(int j = i+1; j < n; ++j){
            if( i == j) continue;
            int d = getDif(v[i],v[j]);
            if( d > x) continue;
            g[i].push_back(j);
            g[j].push_back(i);
        }
    }
    deu = false;
    dfs(0);
    if(!deu){
        cout << "impossivel\n"; return 0;
    }
    

    // reverse(all(path));
    path.pb(path[0]);
    for(int i = 0; i < path.size(); ++i){
        int t = path[i];
        cout << v[t];
        if( i < path.size() -1 ){
            cout << " -> ";
        }else{
            cout << "\n";
        }
    }
    return 0;
}
