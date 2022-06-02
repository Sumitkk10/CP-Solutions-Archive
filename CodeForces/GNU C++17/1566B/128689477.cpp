#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
    string s;
    cin >> s;
    int n = s.size(), ans = 0;
    s = ' ' + s;
    for(int i = 1; i <= n; ++i){
        char x = s[i];
        while(s[i] == x and i <= n)
            ++i;
        --i;
        if(x == '0') 
            ++ans;
    }
    cout << min(2, ans) << '\n';
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
