#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define vii vector<ll> 
#define pb push_back
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 7, N = 27;
vector<int> graph[N];
bool vis[N], flag;

void dfs(int a, int b){
    if(a == b){
        flag = 1;
        return;
    }
    vis[a] = true;
    for(int i = 0; i < graph[a].size(); ++i){
        if(vis[graph[a][i]] == false)
            dfs(graph[a][i], b);
    }
}

int main(){
    fast;
    ll t;
    cin >> t;
    while(t--){
        string a, b;
        cin >> a >> b; 
        ll m;
        cin >> m;
        string s[m];
        for(int i = 0; i < m; ++i){
            cin >> s[i];
            graph[(s[i][0]) - 'a'].pb((s[i][3]) - 'a');
        }
        if(a.size() != b.size()){ 
            cout << "NO\n";
            continue;
        }
        int d = 0;
        for(int i = 0; i < a.size(); ++i){
            if(a[i] != b[i]){
                dfs(a[i] - 'a', b[i] - 'a');
                if(flag == 0){
                    ++d;
                    cout << "NO\n";
                    break;
                }
                flag = 0;
                for(int i = 0; i <= 26; ++i)
                    vis[i] = false;
            }
        }
        if(d == 0) cout << "YES\n";
        for(int i = 0; i < N; ++i){ 
            graph[i].clear();
            vis[i] = false;
        }
    }
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
    return 0;
}