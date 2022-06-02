#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define vii vector<ll> 
#define pb push_back
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 7, N = 1e5 + 3;
vector<ll> graph[N];
ll dist[N];

void dijkstra(ll n){
    set<pair<ll, ll> > st;
    st.insert({n, dist[n]});
    while(st.empty() != true){
        int u = st.begin()->first;
        int dis = st.begin()->second;
        st.erase(st.begin());
        for(auto i : graph[u]){
            if(dist[i] > dis + 1){
                dist[i] = dis + 1;
                st.insert({i, dist[i]});
            }
        }
    }
}

int main(){
    fast;
    ll n, m, q;
    cin >> n >> m >> q;
    for(int i = 1; i <= m; ++i){
        ll x, y;
        cin >> x >> y;
        graph[x].pb(y);
        graph[y].pb(x);
    }
    for(int i = 0; i < N; ++i)
        dist[i] = INT_MAX;
    dist[1] = 0;
    dijkstra(1);
    vii ans[N];
    for(int i = 1; i <= n; ++i)
        ans[dist[i]].pb(graph[i].size());
  	for(int i = 1; i <= n; ++i) sort(ans[i].begin(),ans[i].end());
    for(int i = 1; i <= q; ++i){
        ll x, y;
        cin >> x >> y;
        int no = 0;
        int low = 0,high = ans[x].size()-1;
      	while(low<=high){
          int mid = (low + high) /2;
          if(ans[x][mid] == y){
            	cout << "YES\n" ;
            	++no;
            	break;
          } 
          if(ans[x][mid] > y) high = mid -  1;
          else low = mid + 1;
        } 
        if(no == 0) cout <<"NO\n";
    }
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
    return 0;
}