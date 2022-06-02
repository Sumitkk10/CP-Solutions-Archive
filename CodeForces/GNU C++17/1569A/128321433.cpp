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
    for(int l = 0; l < s.size() - 1; ++l){
        if(s[l] != s[l + 1]){
            cout << l + 1 << ' ' << l + 2 << '\n';
            return;
        }
    }
    cout << "-1 -1\n";
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
