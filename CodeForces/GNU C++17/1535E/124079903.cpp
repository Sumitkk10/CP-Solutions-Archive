#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
long long q, amt[N], cost[N], dp[N][22];

void solve(){
    cin >> q >> amt[0] >> cost[0];
    memset(dp, -1, sizeof dp);
    for(int node = 1; node <= q; ++node){
        int type;
        cin >> type;
        if(type == 1){
            int p;
            cin >> p >> amt[node] >> cost[node];
            for(int lvl = 0; lvl <= 20; ++lvl){
                if(lvl == 0){
                    dp[node][lvl] = p;
                    continue;
                }
                if(dp[node][lvl - 1] == -1) break;
                dp[node][lvl] = dp[dp[node][lvl - 1]][lvl - 1];
            }
            continue;
        }
        long long int vertex, amount;
        cin >> vertex >> amount;
        int cur_node = vertex;
        long long ans = 0, ok = 0;
        while(amount > 0 and amt[vertex] > 0){
            cur_node = vertex;
            for(int jump = log2(node) + 2; jump >= 0; --jump)
                if(dp[cur_node][jump] != -1 and amt[dp[cur_node][jump]] > 0)
                    cur_node = dp[cur_node][jump];
            long long mn = min(amt[cur_node], amount);
            amount -= mn;
            ans += (mn * cost[cur_node]);
            ok += mn;
            amt[cur_node] -= mn;
        }
        cout << ok << " " << ans << endl;
    }
}

int main(){
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}
