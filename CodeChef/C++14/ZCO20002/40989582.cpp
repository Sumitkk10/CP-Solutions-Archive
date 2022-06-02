#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 102;
const int MOD = 1e8 + 7;
int n, m, k, a[N], b[N], dp[N][N][N + N][3];
vector<int> c;

long long int go(int i, int j, int blocks, int pre){
    if(i > n or j > m or blocks > k)
        return 0;
    if(i == n and j == m)
        return (blocks == k);
    if(dp[i][j][blocks][pre] != -1)
        return dp[i][j][blocks][pre];
    long long int ans = 0;
    if(i < n){
        if(pre == 2)
            ans = (ans + go(i + 1, j, 1, 0)) % MOD;
        else if(pre == 0){
            if(a[i] == a[i - 1])
                ans = (ans + go(i + 1, j, blocks, 0)) % MOD;
            else
                ans = (ans + go(i + 1, j, blocks + 1, 0)) % MOD;
        }
        else{
            if(a[i] == b[j - 1])
                ans = (ans + go(i + 1, j, blocks, 0)) % MOD;
            else
                ans = (ans + go(i + 1, j, blocks + 1, 0)) % MOD;
        }
    }
    if(j < m){
        if(pre == 2)
            ans = (ans + go(i, j + 1, 1, 1)) % MOD;
        else if(pre == 1){
            if(b[j] == b[j - 1])
                ans = (ans + go(i, j + 1, blocks, 1)) % MOD;
            else
                ans = (ans + go(i, j + 1, blocks + 1, 1)) % MOD;
        }
        else{
            if(b[j] == a[i - 1])
                ans = (ans + go(i, j + 1, blocks, 1)) % MOD;
            else
                ans = (ans + go(i, j + 1, blocks + 1, 1)) % MOD;
        }
    }
    return dp[i][j][blocks][pre] = ans;
}

void solve(){
    memset(dp, -1, sizeof(dp));
    cin >> n >> m >> k;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    for(int i = 0; i < m; ++i)
        cin >> b[i];
    cout << go(0, 0, 0, 2) << '\n';
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
