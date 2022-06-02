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
    int a[n + 1], b[n + 1];
    queue<int> q;
    bool vis[n + 1];
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        q.push(a[i]);
        vis[i] = 0;
    }
    for(int i = 1; i <= n; ++i)
        cin >> b[i];
    int j = 1, ans = 0;
    while(!q.empty() and j <= n){
        int x = q.front();
        if(vis[x]){ 
            q.pop();
            continue;
        }
        if(x == b[j]) q.pop();
        else{
            if(!vis[b[j]]) ++ans;
            vis[b[j]] = true;
        }
        ++j;
    }
    cout << ans << '\n';
}

int main(){
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}
