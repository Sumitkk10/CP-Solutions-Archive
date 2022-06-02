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
    char a[n + 1][m + 1];
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            cin >> a[i][j];
    bool ok = 1, okk = 1;
    char first[n + 1][m + 1], second[n + 1][m + 1];
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if((i + j) % 2 == 0){
                first[i][j] = 'R';
                second[i][j] = 'W';
            }
            else{
                first[i][j] = 'W';
                second[i][j] = 'R';
            }
            if(a[i][j] != '.'){
                if(a[i][j] != first[i][j]) ok = 0;
                if(a[i][j] != second[i][j]) okk = 0;
            }
        }
    }
    if(ok){
        cout << "YES\n";
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= m; ++j)
                cout << first[i][j];
            cout << '\n';
        }
        return;
    }
    if(okk){
        cout << "YES\n";
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= m; ++j)
                cout << second[i][j];
            cout << '\n';
        }
        return;
    }
    cout << "NO\n";
}

int main(){
    fast;
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
