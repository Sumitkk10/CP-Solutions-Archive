#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define vii vector<ll> 
#define pb push_back
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 7, N = 1e6 + 3;
vector<pair<int, int> > graph[N];
bool vis[N];
int cnt, strength;

void dfs(int n){
    vis[n]= true;
    for(auto i : graph[n]){
        if(!vis[i.first] && i.second <= strength){
            ++cnt;
            dfs(i.first);
        }
    }
}

int main(){
    fast;
    ll n, m;
    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        ll x, y, p;
        cin >> x >> y >> p;
        graph[x].pb({y, p});
        graph[y].pb({x, p});
    }
    ll q;
    cin >> q >> strength;
    while(q--){
        ll x;
        cin >> x;
        if(!vis[x]){
            ++cnt;
            dfs(x);
        }
    }
    cout << cnt;
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
    return 0;
}