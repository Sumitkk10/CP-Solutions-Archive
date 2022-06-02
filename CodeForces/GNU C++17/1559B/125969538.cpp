#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 100 + 5;
const int MOD = 1e9 + 7;

void solve(){
    int n;
    string s;
    cin >> n >> s;
    long long dp[n + 1][4];
    s = " " + s;
    memset(dp, 0, sizeof dp);
    for(int i = 1; i <= s.size(); ++i){
        if(s[i] == '?'){
            dp[i][0] = min(dp[i - 1][0] + 1, dp[i - 1][1]);
            dp[i][1] = min(dp[i - 1][1] + 1, dp[i - 1][0]);
        }
        else if(s[i] == 'R'){
            dp[i][0] = min(dp[i - 1][0] + 1, dp[i - 1][1]);
            dp[i][1] = INT_MAX;
        }
        else{
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][1] + 1);
            dp[i][0] = INT_MAX;
        }
    }
    int cur = n;
    string ans;
    if(dp[cur][0] <= dp[cur][1]){
        ans.push_back('R');
        while(cur > 1){
            if(ans.back() == 'R'){
                if(dp[cur - 1][0] + 1 <= dp[cur - 1][1])
                    ans.push_back('R');
                else
                    ans.push_back('B');
            }
            else{
                if(dp[cur - 1][1] + 1 <= dp[cur - 1][0])
                    ans.push_back('B');
                else
                    ans.push_back('R');
            }
            --cur;
        }
    }
    else{
        ans.push_back('B');
        while(cur > 1){
            if(ans.back() == 'R'){
                if(dp[cur - 1][0] + 1 <= dp[cur - 1][1])
                    ans.push_back('R');
                else
                    ans.push_back('B');
            }
            else{
                if(dp[cur - 1][1] + 1 <= dp[cur - 1][0])
                    ans.push_back('B');
                else
                    ans.push_back('R');
            }
            --cur;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << "\n";
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
