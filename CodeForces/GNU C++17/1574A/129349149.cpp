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
    int cur = n;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < cur; ++j)
            cout << "(";
        for(int j = 0; j < cur; ++j)
            cout << ")";
        for(int j = 0; j < n - cur; ++j)
            cout << "(";
        for(int j = 0; j < n - cur; ++j)
            cout << ")";
        cur--;
        cout << '\n';
    }
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
