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
    string s, t;
    cin >> s >> t;
    string a, b;
    a = s, b = t;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    if(a != b){
        cout << "NO\n";
        return;
    }
    map<char, int> mp;
    for(auto k : s)
        mp[k]++;
    bool ok = 0;
    for(auto k : mp)
        if(k.second > 1)
            ok = 1;
    if(ok){
        cout << "YES\n";
        return;
    }
    int par = 0, par1 = 0;
    for(int i = 0; i < n; ++i)
        for(int j = i + 1; j < n; ++j)
            if((s[i] - 'a') > (s[j] - 'a'))
                ++par;
    for(int i = 0; i < n; ++i)
        for(int j = i + 1; j < n; ++j)
            if((t[i] - 'a') > (t[j] - 'a'))
                ++par1;
    // cout << par << ' ' << par1 << ' ';
    cout << ((par % 2) == (par1 % 2) ? "YES\n" : "NO\n");
}

int main(){
    fast;
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
