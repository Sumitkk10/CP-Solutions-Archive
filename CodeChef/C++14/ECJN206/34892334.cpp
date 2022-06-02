#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define vii vector<ll> 
#define pb push_back
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 7, N = 1e3 + 3;
vector<int> graph[N];
string x[N], y[N];
map<string, int> mp;
string a, b;
bool vis[N];

void dfs(ll s){
    vis[s] = 1;
    for(int i = 0; i < graph[s].size(); ++i){
        if(vis[graph[s][i]] == 0){
            dfs(graph[s][i]);
        }
    }
}

int main(){
    fast;
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n >> a >> b;
        int ct = 1;
        mp[a] = ct++;
        mp[b] = ct++;
        for(int i = 0; i < n; ++i){
            cin >> x[i] >> y[i];
            if(mp.find(x[i]) == mp.end()){
                mp[x[i]] = ct++; 
            }
            if(mp.find(y[i]) == mp.end()){
                mp[y[i]] = ct++;
            }
        }
        for(int i = 0; i < n; i++){
            graph[mp[x[i]]].push_back(mp[y[i]]);
            graph[mp[y[i]]].push_back(mp[x[i]]);
        }
        dfs(mp[a]);
        if(vis[mp[b]] == 0)
            cout << "Stay Home, Stay Safe\n";
        else
            cout << "Quarantine\n";
        for(int i = 0; i < N; ++i){
            graph[i].clear();
            vis[i] = 0;
        }
        mp.clear();
    }
    return 0;
}