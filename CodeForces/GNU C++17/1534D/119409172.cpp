#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
int n;

vector<int> query(int x){
    cout << "? " << x << endl;
    vector<int> v(n);
    for(auto& dis : v)
        cin >> dis;
    return v;
}

void solve(){
    cin >> n;
    vector<int> cur = query(1), odd, even;
    map<pair<int, int>, bool> mp;
    vector<pair<int, int> > edges;
    for(int i = 0; i < cur.size(); ++i){
        if(cur[i] == 1 and !mp[{i + 1, 1}] and !mp[{1, i + 1}]){
            edges.push_back({1, i + 1});
            mp[{1, i + 1}] = true;
            mp[{i + 1, 1}] = true;
        }
        if(cur[i] % 2) odd.push_back(i + 1);
        else if(cur[i]) even.push_back(i + 1);
    }
    if(odd.size() < even.size()){
        for(auto k : odd){
            vector<int> ok = query(k);
            for(int node = 0; node < ok.size(); ++node){
                if(ok[node] == 1 and !mp[{node + 1, k}] and !mp[{k, node + 1}]){
                    edges.push_back({k, node + 1});
                    mp[{k, node + 1}] = mp[{node + 1, k}] = true;
                }
            }
        }
        cout << "!" <<endl;
        for(auto k : edges)
            cout << k.first << ' ' << k.second << endl;
        return;
    }
    for(auto k : even){
            vector<int> ok = query(k);
            for(int node = 0; node < ok.size(); ++node){
                if(ok[node] == 1 and !mp[{node + 1, k}] and !mp[{k, node + 1}]){
                    edges.push_back({k, node + 1});
                    mp[{k, node + 1}] = mp[{node + 1, k}] = true;
                }
            }
        }
        cout << "!" <<endl;
        for(auto k : edges)
            cout << k.first << ' ' << k.second << endl;
        return;
}

int main(){
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}
