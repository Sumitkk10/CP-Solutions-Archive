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
    char a[n + 1][n + 1];
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            a[i][j] = '.';
    a[2][2] = 'Q';
    for(int i = 4; i <= n; ++i)
        a[i][i] = 'Q';
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            cout << a[i][j];
        }
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