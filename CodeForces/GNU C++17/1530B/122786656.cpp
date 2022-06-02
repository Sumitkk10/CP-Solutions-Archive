#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int> > a(n + 1, vector<int>(m + 1, 0));
    for(int i = 1; i <= n; ++i){
        if(i % 2 == 1){
            a[i][1] = 1;
            a[i][m] = 1;
        }
    }
    for(int j = 3; j <= m - 2; j += 2){
        a[1][j] = 1;
        a[n][j] = 1;
    }
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            cout << a[i][j];
        }
        cout << '\n';
    }
    cout << '\n';
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
