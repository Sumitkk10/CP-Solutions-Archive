#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;


int main(){
    fast;
    ll n, m;
    cin >> n >> m;
    char mat[n+2][m+2];
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            cin >> mat[i][j];
    ll q;
    cin >> q;   
    ll matt[n+2][m+2];
    memset(matt, 0, sizeof matt);
    while(q--){
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        matt[x1][y1]++;
        matt[x2 + 1][y2 + 1]++;
        matt[x1][y2 + 1]--;
        matt[x2 + 1][y1]--;
    }
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            matt[i][j] += matt[i - 1][j] + matt[i][j - 1] - matt[i - 1][j - 1];
            // cout << matt[i][j] << " ";
        }
        // cout << endl;
    }
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(mat[i][j] == '0'){
                // cout << "yo ";
                if(matt[i][j] % 2 == 0) cout  << "0";
                else  cout << "1";
                continue;
            }
            if(matt[i][j] % 2 == 0) cout << "1";
            else cout << "0";
        }
        cout << "\n";
    }
    return 0;
}
