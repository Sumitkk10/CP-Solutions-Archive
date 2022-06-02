#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define vii vector<ll> 
#define pb push_back
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 7, N = 1e3 + 3;
ll grid[N][N], pre_sum[N][N];

int main(){
    fast;
    ll t;
    cin >> t;
    while(t--){
        ll n, m;
        cin >> n >> m;
        for(int i = 0; i < m; ++i){
            int x, y;
            cin >> x >> y;
            grid[x][y] = 1;
        }
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n ; ++j)
                pre_sum[i][j] = grid[i][j] + pre_sum[i-1][j] + pre_sum[i][j-1] - pre_sum[i-1][j-1];
        int mx = 0;
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n ; ++j){
                int k = min(pre_sum[i][j], min((pre_sum[n][n] - pre_sum[i][n] - pre_sum[n][j] + pre_sum[i][j]), min((pre_sum[i][n] - pre_sum[i][j]), (pre_sum[n][j] - pre_sum[i][j]))));
                mx = max(mx, k);
            }
        }
        cout << mx << "\n";
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < N; ++j){ 
                pre_sum[i][j] = 0;
                grid[i][j] = 0;
            }
        }
    }
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
    return 0;
}