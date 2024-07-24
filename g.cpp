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

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,m; cin >> n >> m;
    m*=60;
    vector<int> t(n),e(n);
    FOR(i,n){
        cin >> t[i] >> e[i];
    }
    int at = 1, lst = 0;
    vector<vector<int>> dp(2, vi(m+1));
    FOR(i,m+1) dp[0][i] = -1;
    dp[0][0] = 0;
    for(int i = 1; i <= n; ++i){
        int tem = t[i-1], val = e[i-1];
        for(int j = 0; j <= m; ++j){
            dp[at][j] = dp[lst][j];
            if( j >= tem and dp[lst][j-tem] != -1){
                dp[at][j] = max(dp[at][j], dp[lst][j-tem] + val);
            }
        }
        swap(at,lst);
    }
    swap(at,lst);
    int ans = 0;
    for(int i = 0; i <= m; ++i){
        ans = max(ans, dp[at][i]);
    }
    cout << ans << endl;
    return 0;
}
