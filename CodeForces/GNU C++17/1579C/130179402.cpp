#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<char> > a(n + 1, vector<char>(m + 1));
    vector<vector<bool> > ans(n + 1, vector<bool>(m + 1));
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            cin >> a[i][j];
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(a[i][j] == '*'){
                int cur_i = i, cur_j = j, ct = 0;
                while(a[cur_i][cur_j] == '*' and cur_i > 0 and cur_j > 0){
                    --cur_i;
                    --cur_j;
                    ++ct;
                }
                --ct;
                cur_i = i, cur_j = j;
                int ctt = 0;
                while(a[cur_i][cur_j] == '*' and cur_j <= m and cur_i > 0){
                    --cur_i;
                    ++cur_j;
                    ++ctt;
                }
                --ctt;
                int x = min(ct, ctt);
                if(x < k) continue;
                ans[i][j] = true;
                cur_i = i - 1, cur_j = j - 1;
                while(x--){
                    ans[cur_i][cur_j] = true;
                    --cur_i;
                    --cur_j;
                }
                x = min(ct, ctt);
                cur_i = i - 1, cur_j = j + 1;
                while(x--){
                    ans[cur_i][cur_j] = true;
                    --cur_i;
                    ++cur_j;
                }
            }
        }
    }
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(a[i][j] == '*' and !ans[i][j]){
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
