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
    map<char, int> mp;
    for(auto k : s)
        mp[k]++;
    if(mp['L'] and mp['O'] and mp['V'] and mp['E']) cout << "FOUND\n";
    else cout << "NOT FOUND\n";
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
