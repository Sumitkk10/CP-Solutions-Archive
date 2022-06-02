#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(c) c.begin(), c.end()
#define endl "\n"

const double PI=3.14159265358979323846264338327950288419716939937510582097494459230;


void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define dbg(x...) cerr << "LINE(" << __LINE__ << ") -> " <<"[" << #x << "] = ["; _print(x)
#else
#define dbg(x...)
#endif

void print(){cerr << endl;};
template <typename T, typename... Args>
void print(T one, Args... rest){
    cerr << one << " ";
    print(rest...);
}

vector<int> adj[200003];
int cnt[200003][28], up[200003][33], dist[200003];

void dfs(int u, string& s, int p){
    for(int v : adj[u]){
        if(v == p)continue;
        for(int i = 0 ;i < 26; ++i)
        	cnt[v][i] = cnt[u][i];
        cnt[v][s[v]-'a']++;
        up[v][0] = u;
        dist[v] = dist[u]+1;
        for(int j = 1;j<21;++j)
            up[v][j] = up[up[v][j-1]][j-1];
        dfs(v, s, u);
    }
}

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = "0"+s;
    for(int i = 0; i <= n; ++i){
    	adj[i].clear();
    	for(int j = 0; j < 26; ++j)
    		cnt[i][j] = 0;
    	for(int j = 0; j < 31; ++j)
    		up[i][j] = 0;
    	dist[i] = 0;
    }
    for(int i =0;i<n-1;++i){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    
    cnt[1][s[1]-'a'] = 1;
    up[1][0] = 1;
    dfs(1,s,-1);
    int q;
    cin >> q;
    while(q--){
        int u,v;
        cin >> u >> v;
        int a = u, b = v;
        if(u == 1 || v == 1){
            cout << "NO" << endl;
            continue;
        }
        if(dist[v] > dist[u])swap(v, u);
        int k = dist[u] - dist[v];
        while(k){
        	int x = (int) log2(k);
        	u = up[u][x];
        	k -= (1 << x);
        }
        int lca = 1;
        if(u == v){
            lca = u;
        }else{
            for(int j = 21;j>=0;--j){
                if(up[u][j]!=up[v][j]){
                    u = up[u][j];
                    v = up[v][j];
                }
            }
            lca = up[u][0];
        }
        bool ok = 0;
        for(int i = 0; i < 26; ++i){
        	int cnt1a = cnt[a][i];
            int cnt2b = cnt[b][i];
            int cnt3lca = cnt[lca][i];
            cnt1a -= cnt3lca;
            cnt2b-=cnt3lca;
            if(cnt1a > 0 && cnt2b > 0){
                ok = 1;
                break;
            }
        }
        if(ok){
            cout << "YES" << endl;
        }else cout << "NO" << endl;
    }

}   

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    

    int T=1;
    cin >> T;
    for(int i = 1;i<=T;++i)
    {
        solve();
    }
}