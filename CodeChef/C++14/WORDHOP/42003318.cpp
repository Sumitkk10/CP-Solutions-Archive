#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
using namespace std;
const int N = 100 + 5;
const int MOD = 1e9 + 7;
vector<int> graph[N], topological;
string s[N];
bool vis[N];
int n, dis[N];
map<pair<int, int>, bool> mp;

bool check(string a, string b){
    if(a.size() == b.size()){
        int j = 0, ct = 0;
        for(int i = 0; i < a.size(); ++i){
            if(a[i] != b[j]){
                if(ct) return false;
                if(a[i] > b[j]) return false;
                ++ct;
                bool ok = 0;
                for(int k = i + 1; k < a.size(); ++k)
                    if(a[k] == b[j])
                        ok = 1;
                if(!ok)
                    return false;
            }
            ++j;
        }
        if(ct == 1)
            return true;
    }
    if(a.size() == b.size() + 1) {
        int j = 0, ct = 0;
        for (int i = 0; i < b.size(); ++i) {
            if (a[j] != b[i]) {
                if (ct)
                    return false;
                ++ct;
                --i;
            }
            ++j;
        }
        return true;
    }
    return false;
}

void dfs(int source, int height){
    vis[source] = 1;
    dis[source] = height;
    for(auto k : graph[source]) {
        if (!vis[k])
            dfs(k, height + 1);
        else {
            dis[k] = max(dis[k], dis[source] + 1);
        }
    }
    topological.push_back(source);
}

void topo(){
    for(int i = 0; i < n; ++i)
        if(!vis[i])
            dfs(i, 1);
    reverse(topological.begin(), topological.end());
}

int main() {
    fast;
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> s[i];
    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j){
            string a = s[i], b = s[j];
            if(check(a, b)) {
                graph[i].push_back(j);
                mp[{i, j}] = true;
            }
            else if(check(b, a)) {
                graph[j].push_back(i);
                mp[{j, i}] = true;
            }
        }
    }
    topo();
    int longest = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++)
            dis[j] = -1e8;
        dis[i] = 0;

        for (int j=0; j<n; j++) {
            int node = topological[j];
            int len = graph[node].size();
            for (int k=0; k<len; k++) {
                int nx = graph[node][k];
                if (dis[nx]<dis[node]+1)
                    dis[nx] = dis[node] + 1;
            }
        }

        /*for (int i=0; i<n; i++)
            cout << dis[i] << " ";
        cout << endl;*/

        int best = *max_element(dis, dis+n);
        longest = max(longest, best);
    }

    if (longest < 0) {
        cout << 0 << endl;
    } else if (longest == 0) {
        cout << 0 << endl;
    } else {
        cout << longest+1 << endl;
    }
    return 0;
}
/*
11
abacd
bcdada
dd
abcd
bcdd
adcd
addd
aa
ccd
add
ad
 */