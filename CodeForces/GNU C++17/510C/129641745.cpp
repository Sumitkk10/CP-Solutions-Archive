#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
    int n;
    cin >> n;
    string a[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    map<int, int> in;
    vector<int> graph[26];
    for(int i = 1; i <= n - 1; ++i){
        string cur = a[i], nxt = a[i + 1];
        for(int j = 0; j < cur.size(); ++j){
            if(j >= nxt.size()){
                cout << "Impossible\n";
                return;
            }
            if(cur[j] != nxt[j]){
                in[nxt[j] - 'a']++;
                graph[cur[j] - 'a'].push_back(nxt[j] - 'a');
                break;
            }
        }
    }
    string ans;
    queue<int> q;
    bool vis[26];
    for(int i = 0; i < 26; ++i){
        vis[i] = 0;
        if(!in[i]){
            q.push(i);
            vis[i] = true;
        }
    }
    while(!q.empty()){
        int x = q.front();
        q.pop();
        ans.push_back(x + 'a');
        for(auto k : graph[x]){
            in[k]--;
            if(!vis[k] and !in[k]){
                vis[k] = true;
                q.push(k);
            }
        }
    }
    if(ans.size() != 26){
        cout << "Impossible\n";
        return;
    }
    cout << ans << '\n';
}

int main(){
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}
