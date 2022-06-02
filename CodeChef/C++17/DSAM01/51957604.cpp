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
    map<char, bool> read;
    for(auto k : s)
        read[k] = true;
    int q;
    cin >> q;
    while(q--){
        string cur;
        cin >> cur;
        bool bad = false;
        for(auto k : cur){
            if(!read[k]){
                bad = true;
                break;
            }
        }
        if(!bad) cout << "Yes\n";
        else cout << "No\n";
    }
}

int main(){
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}
