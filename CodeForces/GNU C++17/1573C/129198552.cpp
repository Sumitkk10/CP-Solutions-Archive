#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
vector<int> graph[N];

void solve(){
    int n;
    cin >> n;
    map<int, int> in;
    for(int i = 1; i <= n; ++i){
        int k;
        cin >> k;
        in[i] = k;
        for(int j = 1; j <= k; ++j){
            int x;
            cin >> x;
            graph[x].push_back(i);
        }
    }
    queue<pair<int, int> > q;
    bool vis[n + 1];
    vector<int> wut(n + 1, 0);
    memset(vis, 0, sizeof vis);
    for(int i = 1; i <= n; ++i){
        if(!in[i]){
            vis[i] = true;
            q.push({i, 1});
            wut[i] = 1;
        }
    }
    int mx = 1;
    while(!q.empty()){
        int node = q.front().first;
        int time = q.front().second;
        mx = max(mx, time);
        q.pop();
        for(auto k : graph[node]){
            in[k]--;
            if(!vis[k] and k > node)
                wut[k] = max(wut[k], time);
            else if(!vis[k])
                wut[k] = max(wut[k], time + 1);
            if(in[k] == 0){
                if(k > node){
                    wut[k] = max(wut[k], time);
                    q.push({k, wut[k]});
                }
                else{
                    wut[k] = max(wut[k], time + 1);
                    q.push({k, wut[k]});
                }
                vis[k] = true;
            }
        }
    }
    for(int i = 1; i <= n; ++i)
        graph[i].clear();
    for(int i = 1; i <= n; ++i){
        if(!vis[i]){
            cout << "-1\n";
            return;
        }
    }
    cout << mx << '\n';
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
