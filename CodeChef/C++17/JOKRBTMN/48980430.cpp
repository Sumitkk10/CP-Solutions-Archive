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
    map<int, int> comp;
    for(int i = 1; i <= m; ++i){
        int len;
        cin >> len;
        while(len--){
            int x;
            cin >> x;
            comp[x] = i - 1;
        }
    }
    int ans = 1, pre = 0;
    for(int i = 0; i < k; ++i){
        int x;
        cin >> x;
        if(i == 0){
            pre = x;
            continue;
        }
        if(comp[x] == comp[pre]) continue;
        ++ans;
        pre = x;
    }
    cout << ans << '\n';
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
