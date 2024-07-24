#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(int i = 0; i < n; ++i)
#define endl '\n'

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    vector<string> g(n);
    FOR(i,n) cin >> g[i];
    bool ok = 1;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if( i == j) continue;
            ok &= g[i][j]==g[j][i];
        }
    }
    cout << ( ok ? "Sim" : "Nao") << endl;
    return 0;
}
