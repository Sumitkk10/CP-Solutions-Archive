#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
    ll n, ans = 0;
    cin >> n;
    char a[n + 2][3];
    a[0][1] = 'z';
    a[0][2] = 'z';
    a[n + 1][1] = 'z';
    a[n + 1][2] = 'z';
    for(int i = 1; i <= n; ++i)
        cin >> a[i][1];
    for(int i = 1; i <= n; ++i)
        cin >> a[i][2];
    bool vis[n + 1];
    memset(vis, 0, sizeof vis);
    for(int i = 1; i <= n; ++i){
        if(a[i][1] == '0' and a[i][2] == '1' and !vis[i]){
            vis[i] = true;
            ++ans;
        }
        else if(a[i][2] == '1'){
            if(a[i - 1][1] == '1' and !vis[i - 1]){
                vis[i - 1] = true;
                ++ans;
            }
            else if(a[i + 1][1] == '1' and !vis[i + 1]){
                vis[i + 1] = true;
                ++ans;
            }
        }
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
}
