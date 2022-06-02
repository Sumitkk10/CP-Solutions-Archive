#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
    int n;
    cin >> n;
    string s[2];
    cin >> s[0] >> s[1];
    s[0] = ' ' + s[0];
    s[1] = ' ' + s[1];
    int ans = 0;
    for(int i = 1; i <= n; ++i){
        if((s[0][i] == '0' and s[1][i] == '1') or (s[0][i] == '1' and s[1][i] == '0')){
            ans += 2;
            continue;
        }
        if(s[0][i] == '0' and s[1][i] == '0'){
            if(i == n){
                ++ans;
                continue;
            }
            if(s[0][i + 1] == '1' and s[1][i + 1] == '1'){
                ans += 2;
                ++i;
                continue;
            }
            ++ans;
            continue;
        }
        while(s[0][i] == '1' and s[1][i] == '1' and i <= n)
            ++i;
        if(i <= n)
            ans += 2;
    }
    cout << ans << '\n';
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
