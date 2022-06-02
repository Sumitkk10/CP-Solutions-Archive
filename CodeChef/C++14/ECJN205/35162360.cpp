#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 7, N = 1e4 + 3;

bool treat[N];
std::vector<ll> v[N];
ll dist[N];

int main(){
    fast;
    ll t;
    cin >> t;
    while(t--){
        ll n, m;
        cin >> n >> m;
        for(int i = 0; i < m; i++){
            int x;
            cin >> x;
            treat[x] = true;
        }
        ll q;
        cin >> q;
        while(q--){
            int x, y;
            cin >> x >> y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        // for(int i = 1; i <= n; i++) cout << treat[i] << ' ';
        // cout << endl;
        ll a, b;
        cin >> a >> b;
        //dijkistra
        for(int i = 1; i <= n; i++) dist[i] = INT_MAX;
        dist[a] = 0;
        set<pair<int, int> > st;
        st.insert({dist[a], a});
        while(st.size() != 0){   
            int curnode = st.begin()->second;
            int curdist = st.begin()->first;
            st.erase(st.begin());
            for(auto i: v[curnode]){
                if(treat[i] == false) continue;
                if(dist[i] > curdist + 1){
                    //cout << "Yo\n";
                    dist[i] = curdist + 1;
                    st.insert({dist[i], i});
                }
            }
        }
        if(dist[b] == INT_MAX) cout << -1 << '\n';
        else cout << dist[b]  << '\n';
        for(int i = 0; i <= n; i++){
            v[i].clear();
            treat[i] = false;
        }


    }

    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
    return 0;
}