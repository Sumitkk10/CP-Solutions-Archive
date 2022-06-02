#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define pb push_back
using namespace std;
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int suf_dp[n + 1], pre_dp[n + 1];
    pre_dp[0] = suf_dp[n - 1] = 1;
    for(int i = 1; i < n; ++i){
        if(s[i] != s[i - 1])
            pre_dp[i] = pre_dp[i - 1] + 1;
        else
            pre_dp[i] = 1;
    }
    for(int i = n - 2; i >= 0; --i){
        if(s[i] != s[i + 1])
            suf_dp[i] = suf_dp[i + 1] + 1;
        else
            suf_dp[i] = 1;
    }
    if(s[0] == 'L')
        cout << "1 ";
    else
        cout << suf_dp[0] + 1 << ' ';
    for(int i = 1; i < n; ++i){
        if(s[i - 1] == 'R' and s[i] == 'L')
            cout << "1 ";
        else if(s[i - 1] == 'L' and s[i] == 'R')
            cout << pre_dp[i] + suf_dp[i] << ' ';
        else if(s[i] == 'L')
            cout << pre_dp[i - 1] + 1 << " ";
        else
            cout << suf_dp[i] + 1 << " ";
    }
    if(s[n - 1] == 'R')
        cout << "1 ";
    else
        cout << pre_dp[n - 1] + 1 << ' ';
    cout << "\n";
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}