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
    vector<pair<int, pair<int, pair<int, int> > > > v;
    for(int i = 1; i <= n; ++i){
        int x, y, z;
        cin >> x >> y >> z;
        v.push_back({x, {y, {z, i}}});
    }
    vector<pair<int, int> > ans;
    while(!v.empty()){
        sort(v.rbegin(), v.rend());
        int x = v[0].first, y = v[0].second.first, z = v[0].second.second.first, pos = v[0].second.second.second;
        int index, dis = INT_MAX;
        for(int i = 1; i < v.size(); ++i){
            int d = abs(v[i].first - x) + abs(v[i].second.first - y) + abs(v[i].second.second.first - z);
            if(d < dis){
                dis = d;
                index = i;
            }
        }
        ans.push_back({pos, v[index].second.second.second});
        v.erase(v.begin());
        v.erase(v.begin() + index - 1);
    }
    for(auto k : ans)
        cout << k.first << ' ' << k.second << endl;
}

int main(){
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}
