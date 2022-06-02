#include<bits/stdc++.h>
#define ll long long int
#define ld long double
using namespace std;
const int MOD = 1e9 + 7, N = 1e6+3;
vector<ll> adjl[N];
ll cnt = 0;
bool vis[N];

void dfs(ll n){
    cnt++;
    vis[n] = true;
    for(int i = 0; i < adjl[n].size(); ++i){
        if(vis[adjl[n][i]] == false)
            dfs(adjl[n][i]);
    }
    return;
}

int main(){
    ll t;
    cin >> t;
    while(t--){
        ll nodes, k;
        cin >> nodes >> k;
        int x, y;
        for(int i = 0; i < k; ++i){
            cin >> x >> y;
            adjl[x].push_back(y);
            adjl[y].push_back(x);
        }
        vector<ll> ans;
        for(int i = 0; i < nodes; ++i){
            if(vis[i] == false){
                dfs(i);
                ans.push_back(cnt);
                cnt = 0;
            }
        }
        sort(ans.begin(), ans.end());
        cout << ans.size() << '\n';
        for(int i = 0; i < ans.size(); ++i)
            cout << ans[i] << ' ';
        cout << '\n';
        for(int i = 0; i < nodes; ++i){
            adjl[i].clear();
            vis[i] = 0;
        }
    }
    return 0;
}