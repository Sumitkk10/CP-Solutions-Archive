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
    string s;
    cin >> s;
    int sum = 0, ans = 0, ok = 0;
    for(int i = 0; i < s.size(); ++i){
        ans += ((s[i] - '0') > 0);
        sum += (s[i] - '0');
    }
    cout << (s[n - 1] == '0' ? ans : ans - 1) + ok/2 + sum << '\n';
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
