#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 7;
const int N = 1e6 + 5;
bool vis[N];

void solve(){
    string s;
    cin >> s;
    int n = s.size();
    vector<int> pos[10];
    for(int i = 0; i < s.size(); ++i)
        pos[s[i] - '0'].push_back(i);
    queue<pair<int, int> > q;
    q.push({0, 0}); // node -- dis;
    vis[0] = true;
    while(!q.empty()){
        int node = q.front().first;
        int dis = q.front().second;
        q.pop();
        if(node == n - 1){
            cout << dis << "\n";
            return;
        }
        if(node >= n)
            return;
        if(!vis[node + 1]) {
            q.push({node + 1, dis + 1});
            vis[node + 1] = true;
        }
        if(node - 1 >= 0 and !vis[node - 1]){
            q.push({node - 1, dis + 1});
            vis[node - 1] = true;
        }
        for(auto k : pos[s[node] - '0']){
            if(k != node + 1 and k != node - 1 and k != node and !vis[k]) {
                q.push({k, dis + 1});
                vis[k] = true;
            }
        }
        pos[s[node] - '0'].clear();
    }
}

int main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}