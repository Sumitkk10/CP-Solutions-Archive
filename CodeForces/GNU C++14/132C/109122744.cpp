#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
string s;
int n, dp[201][60][201][3];

long long go(int i, int left, int cnt, int dir){
    if(left < 0)
        return INT_MIN;
    if(i == s.size()){
        if(left == 0)
            return abs(cnt);
        return INT_MIN;
    }
    if(dp[i][left][cnt][dir] != -1)
        return dp[i][left][cnt][dir];
    long long ans = INT_MIN;
    if(s[i] == 'F'){
        if(dir == 0){
            for(int j = 0; j <= left; ++j){
                if(j % 2)
                    ans = max(ans, go(i + 1, left - j, cnt, 1));
                else
                    ans = max(ans, go(i + 1, left - j, cnt - 1, 0));
            }
        }
        if(dir == 1){
            for(int j = 0; j <= left; ++j){
                if(j % 2)
                    ans = max(ans, go(i + 1, left - j, cnt, 0));
                else
                    ans = max(ans, go(i + 1, left - j, cnt + 1, 1));
            }
        }
    }
    else{
        if(dir == 0){
            for(int j = 0; j <= left; ++j){
                if(j % 2)
                    ans = max(ans, go(i + 1, left - j, cnt - 1, 0));
                else
                    ans = max(ans, go(i + 1, left - j, cnt, 1));
            }
        }
        else{
            for(int j = 0; j <= left; ++j){
                if(j % 2)
                    ans = max(ans, go(i + 1, left - j, cnt + 1, 1));
                else
                    ans = max(ans, go(i + 1, left - j, cnt, 0));
            }
        }
    }
    return dp[i][left][cnt][dir] = ans;
}

void solve(){
    memset(dp, -1, sizeof dp);
    cin >> s >> n;
    cout << go(0, n, 0, 1) << "\n";
}

int main(){
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}
