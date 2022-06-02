#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 2502;
const int MOD = 1e9 + 7;
bool is_safe[N][N];
int n, m, k, dp[N][N];

bool solve(int i, int j){
    if(!is_safe[i][j] or j >= m or i >= n) 
        return 0;
    if(i == n - 1 and j == m - 1)
        return 1;
    if(dp[i][j] != -1)
        return dp[i][j];
    int ans = 0;
    ans |= solve(i + 1, j);
    ans |= solve(i, j + 1);
    return dp[i][j] = ans;
}

int main(){
    fast;
    cin >> n >> m >> k;
    memset(is_safe, 1, sizeof(is_safe));
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i < k; ++i){
        int x, y, str, freq;
        cin >> x >> y >> str >> freq;
        --x, --y;
        for(int j = 0; j < m; ++j){
            int cur = j + x;
            if(cur - str - abs(y - j) < 0) 
                continue;
            if((cur - str - abs(y - j)) % freq == 0)
                is_safe[x][j] = 0; 
        }
        for(int j = 0; j < n; ++j){
            int cur = j + y;
            if(cur - str - abs(j - x) < 0) 
                continue;
            if((cur - str - abs(j - x)) % freq == 0)
                is_safe[j][y] = 0; 
        }
        is_safe[x][y] = 0;
    }
    if(solve(0, 0)){
        cout << "YES\n";
        cout << n + m - 2 << '\n';
        return 0;
    }
    cout << "NO\n";
    return 0;
}
