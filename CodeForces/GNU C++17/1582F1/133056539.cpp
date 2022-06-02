/*
When I get older
I'll be stronger
They'll call me freedom
Just like a wavin' flag.
*/
#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
int n, a[N];
vector<int> dp(515, INT_MAX);

void solve(){
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    dp[0] = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < 515; ++j){
            if(dp[j] < a[i])
                dp[a[i] ^ j] = min(dp[a[i] ^ j], a[i]);
        }
    }
    vector<int> ans;
    for(int i = 0; i < 515; ++i){
        if(dp[i] != INT_MAX)
            ans.push_back(i);
    }
    cout << ans.size() << '\n';
    for(auto k : ans)
        cout << k << ' ';
}

int main(){
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}
