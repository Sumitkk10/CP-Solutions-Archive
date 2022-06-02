#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
using namespace std;
const int MOD = 15746;
const int N = 1e6 + 5;
bool vis[N];
vector<int> graph[N];
int dis[N];

void dijkstra(int str){
    dis[str] = 0;
    set<pair<long long int, int> > s; // dis -- node;
    s.insert({0, str});
    while(!s.empty()){
        int node = s.begin()->second;
        long long int c = s.begin()->first;
        s.erase(s.begin());
        for(auto k : graph[node]){
            if(dis[k] > c + 1){
                dis[k] = c + 1;
                s.insert({dis[k], k});
            }
        }
    }
}

int main(){
    fast;
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i = 1; i <= n; ++i)
        dis[i] = INT_MAX;
    int str, end;
    cin >> str >> end;
    dijkstra(str);
    if(dis[end] == INT_MAX)
        cout << "0\n";
    else
        cout << dis[end] << '\n';
    return 0;
}