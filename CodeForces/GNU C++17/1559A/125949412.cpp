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
    int a[n], andd[n][n];
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        andd[i][i] = a[i];
    }
    for(int i = 0; i < n; ++i){
        int cur = a[i];
        for(int j = i + 1; j < n; ++j){
            cur = (cur & a[j]);
            andd[i][j] = cur;
        }
    }
    int ans = INT_MAX;
    for(int i = 0; i < n; ++i){
        for(int j = i; j < n; ++j)
            ans = min(ans, andd[i][j]);
    }
    cout << ans << "\n";
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
