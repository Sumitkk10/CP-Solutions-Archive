#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 7;
const int N = 50003 + 2;

void solve() {
    string s;
    cin >> s;
    if(s.size() != 10){
        cout << "NO\n";
        return;
    }
    if(s[0] == '0'){
        cout << "NO\n";
        return;
    }
    for(auto k : s){
        if(k >= '0' and k <= '9') continue;
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
}

int main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}