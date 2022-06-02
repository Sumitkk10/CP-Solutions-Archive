#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
int n, a[N];
bool vis[N], ans;

void go(int i, int x){
    if(i == n + 1){
        for(int i = 1; i <= n; ++i){
            if(!vis[i] and abs(a[i]) == abs(x)){
                ans = 1;
                return;
            }
        }
        return;
    }
    vis[i] = true;
    go(i + 1, x + a[i]);
    go(i + 1, x - a[i]);
    vis[i] = false;
    go(i + 1, x);
}

void solve(){
    cin >> n;
    bool ok = 0;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        ok |= (a[i] == 0);
    }
    if(ok){
        cout << "YES\n";
        return;
    }
    go(1, 0);
    cout << (ans ? "YES\n" : "NO\n");
    ans = 0;
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
