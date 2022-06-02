#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int N = 1e6 + 5;
vector<pair<int, int> > graph[N];
int dis[N];

void dijkstra(int source){
    set<pair<long long int, int> > s;
    // dis -- node;
    dis[source] = 0;
    s.insert({0, source});
    while(!s.empty()){
        long long c = s.begin()->first;
        int node = s.begin()->second;
        s.erase(s.begin());
        for(auto k : graph[node]){
            if(dis[k.first] > c + k.second){
                if(s.find({dis[k.first], k.first}) != s.end())
                    s.erase(s.find({dis[k.first], k.first}));
                dis[k.first] = c + k.second;
                s.insert({dis[k.first], k.first});
            }
        }
    }
}

int main() {
    fast;
    int m, a, b;
    for(int i = 1; i <= 2000; ++i)
        dis[i] = INT_MAX;
    cin >> m >> a >> b;
    for(int i = 0; i < m; ++i){
        int u, v, c;
        cin >> u >> c >> v;
        graph[u].push_back({v, c});
        graph[v].push_back({u, c});
    }
    dijkstra(a);
    if(dis[b] == INT_MAX){
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    cout << dis[b] << "\n";
	return 0;
}
