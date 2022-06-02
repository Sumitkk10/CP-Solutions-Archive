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
    int a[n], pos[m];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    vector<int> ans(n, -1);
    for(int i = 0; i < m; ++i){
        cin >> pos[i];
        ans[pos[i] - 1] = 1;
    }
    while(1){
        bool ok = 0;
        for(int i = 0; i < n; ++i){
            if(ans[i] != -1 and a[i] > a[i + 1]){
                ok = 1;
                swap(a[i], a[i + 1]);
            }
        }
        if(!ok)
            break;
    }
    bool ok = 1;
    for(int i = 1; i < n; ++i){
        if(a[i] < a[i - 1]){
            ok = 0;
            break;
        }
    }
    cout << (ok ? "YES\n" : "NO\n");
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
