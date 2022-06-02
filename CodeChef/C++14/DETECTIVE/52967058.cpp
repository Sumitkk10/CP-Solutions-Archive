#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1e9 + 7;
const long long int N = 1e6 + 5;
string s;

void solve(){
    cin >> s;
    int n = s.size(), ans = 0;
    for(int i = 1; i < s.size(); ++i){
        if(s[i] == '?' and s[i - 1] != '?')
            s[i] = s[i - 1];
    }
    for(int i = n - 1; i >= 0; --i){
        if(s[i] == '?' and s[i + 1] != '?')
            s[i] = s[i + 1];
    }
    for(int i = 0; i < n; ++i)
        if(s[i] == '?')
            s[i] = 'L';
    for(int i = 1; i < n; ++i){
        if(s[i] != s[i - 1])
            ++ans;
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);   
    cout.tie(NULL);
    int t = 1, tt = 1;
    cin >> t;
    while(t--){
        cout << "Case #" << tt << ": ";
        solve();
        ++tt;
    }
    return 0;
}