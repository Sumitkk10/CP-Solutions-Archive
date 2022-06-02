#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define vii vector<ll> 
#define pb push_back
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 7, N = 1e4 + 3;

int main(){
    fast;
    ll n, m;
    cin >> n >> m;
    ll gain[n + 1][n + 1], dp[n + 1][n + 1];
    // memset(dp, -1, sizeof(dp));
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            cin >> gain[i][j];
            dp[i][j] = -1e9;
        }
    }
    while(m--){
        int x, y, strength;
        cin >> x >> y >> strength;
        int xx = x, yy = y, ss = strength;
        while(ss >= 0){
            if(xx > n || xx < 1) break;
            int str = ss;
            for(int i = yy; i <= n; ++i){
                if(str == -1) break;
                dp[xx][i] = 0;
                --str;
            }
            str = ss - 1;
            for(int i = yy - 1; i > 0; --i){
                if(str == -1) break;
                dp[xx][i] = 0;
                --str;
            }
            ++xx;
            --ss;
        }
        ss = strength - 1;
        xx = x - 1, yy = y;
        if(xx < 1) continue;
        while(ss > 0){
            if(xx < 1 || xx > n) break;
            int str = ss;
            for(int i = yy; i <= n; ++i){
                if(str == -1) break;
                dp[xx][i] = 0;
                --str;
            }
            str = ss - 1;
            for(int i = yy - 1; i > 0; --i){
                if(str == -1) break;
                dp[xx][i] = 0;
                --str;
            }
            --xx;
            --ss;
        }
    }
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            if(dp[i][j] == -1e9) continue;
            if(i == 1 && j == 1) dp[i][j] = gain[i][j];
            else if(i == 1 && dp[i][j - 1] != -1e9) dp[i][j] = dp[i][j - 1] + gain[i][j];
            else if(i == 1 && dp[i][j - 1] == -1e9) dp[i][j] = -1e9;
            else if(j == 1 && dp[i - 1][j] != -1e9) dp[i][j] = dp[i - 1][j] + gain[i][j];
            else if(j == 1 && dp[i - 1][j] == -1e9) dp[i][j] = -1e9;
            else if(max(dp[i - 1][j], dp[i][j - 1]) == -1e9) dp[i][j] = -1e9;
            else dp[i][j] = gain[i][j] + max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    if(dp[n][n] == -1e9) cout << "NO\n";
    else cout << "YES\n" << dp[n][n];
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
    return 0;   
}