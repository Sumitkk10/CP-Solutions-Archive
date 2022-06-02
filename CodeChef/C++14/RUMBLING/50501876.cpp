#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll x, y;
    cin >> x >> y;
    ll pre[n + 1][2], suf[n + 2][2];
    s = ' ' + s;
    pre[0][0] = pre[0][1] = suf[n + 1][0] = suf[n + 1][1] = 0; 
    for(int i = 1; i <= n; ++i){
        // 0--> means turn him east;
        // 1 --> means turn him west;
        if(s[i] == 'E'){ 
            pre[i][0] = pre[i - 1][0];
            pre[i][1] = pre[i - 1][1] + min(2*x, 2*y);
        }
        else if(s[i] == 'N'){
            pre[i][0] = pre[i - 1][0] + min(3*y, x);
            pre[i][1] = pre[i - 1][1] + min(3*x, y);
        }
        else if(s[i] == 'S'){
            pre[i][0] = pre[i - 1][0] + min(3*x, y);
            pre[i][1] = pre[i - 1][1] + min(3*y, x);
        }
        else{ 
            pre[i][0] = pre[i - 1][0] + min(2*x, 2*y);
            pre[i][1] = pre[i - 1][1];
        }
    }
    for(int i = n; i >= 1; --i){
        if(s[i] == 'E'){ 
            suf[i][0] = suf[i + 1][0];
            suf[i][1] = suf[i + 1][1] + min(2*x, 2*y);
        }
        else if(s[i] == 'N'){ 
            suf[i][0] = suf[i + 1][0] + min(3*y, x);
            suf[i][1] = suf[i + 1][1] + min(3*x, y);
        }
        else if(s[i] == 'S'){
            suf[i][0] = suf[i + 1][0] + min(3*x, y);
            suf[i][1] = suf[i + 1][1] + min(3*y, x);
        }
        else{ 
            suf[i][0] = suf[i + 1][0] + min(2*x, 2*y);
            suf[i][1] = suf[i + 1][1];
        }
    }
    long long ans = LLONG_MAX;
    for(int i = 0; i <= n + 1; ++i){
        // we place a thing here.
        if(i == 0)
            ans = min(ans, suf[i + 1][1]);
        else if(i == n + 1)
            ans = min(ans, pre[i - 1][0]);
        else
            ans = min(ans, pre[i][0] + suf[i + 1][1]);
    }
    cout << ans << "\n";
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
    // you should actually read the stuff at the bottom
}
/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
    * Read other problems if stuck on this one.
*/
