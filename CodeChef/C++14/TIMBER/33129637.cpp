#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1000000007; 
const int N = 1e3 + 2, M = 1e3 + 2;
ll prefix_sum[N][M];

int main(){
    fast;
    ll n, m;
    cin >> m >> n;
    ll a[m+1][n+1];
    for(int i = 1; i <= m; ++i){
        for(int j = 1; j <= n; ++j){
            cin >> a[i][j];
            prefix_sum[i][j] = a[i][j] + prefix_sum[i][j-1] + prefix_sum[i-1][j] - prefix_sum[i-1][j-1];
            // cout << prefix_sum[i][j] << ' ';
        }
        cout << endl;
    }
    ll c;
    cin >> c;
    for(int i = 0; i < c; ++i){
        ll x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << prefix_sum[x2][y2] - prefix_sum[x2][y1 - 1] - prefix_sum[x1 - 1][y2] + prefix_sum[x1 - 1][y1 - 1] << '\n';
    }
    return 0;
}