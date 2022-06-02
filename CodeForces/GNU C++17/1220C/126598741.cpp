#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

// This is a wrong approach

void solve(){
    string s;
    cin >> s;
    int mn = 27;
    for(int i = 0; i < s.size(); ++i){
        mn = min(mn, s[i] - 'a');
        if(mn == s[i] - 'a')
            cout << "Mike\n";
        else cout << "Ann\n";
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
