#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define vii vector<ll> 
#define pb push_back
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 20011, N = 1e4 + 3;
ll r, c, n, l;
ll grid[302][302], dp[302][302][302][2];

int ways(int i, int j, int d, int way){ 
    if(grid[i][j] == 0 || i > r || j > c || d > n)
        return 0;
    if(i == r && j == c)
        return 1;
    if(dp[i][j][d][way] != -1) return dp[i][j][d][way];
    int cnt = 0;
    if(way == 0)
        cnt = (ways(i + 1, j, d + 1, 0)%MOD + ways(i, j + 1, 1, 1) % MOD) % MOD;   
    else 
        cnt = (ways(i + 1, j, 1, 0)%MOD + ways(i, j + 1, d + 1, 1) % MOD) % MOD;
    return dp[i][j][d][way] = cnt;
}

int main(){
    fast;
    cin >> r >> c >> n;
    memset(dp, -1, sizeof(dp));
    for(int i = 1; i <= r; ++i)
        for(int j = 1; j <= c; ++j)
            cin >> grid[i][j];
    cout << ways(1, 1, 0, 0);
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
    return 0;
}