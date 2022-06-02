#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
    long long int n;
    cin >> n;
    map<long long int, vector<int> > pos;
    for(int i = 1; i <= n; ++i){
        long long int x;
        cin >> x;
        pos[x].push_back(i);
    }
    long long ans = 0;
    for(auto k : pos){
        if(k.second.size() < 2) continue;
        vector<pair<long long int, long long int> > v;
        for(int j = 0; j < k.second.size(); ++j)
            v.push_back({k.second[j], n - k.second[j] + 1});
        long long int sum = 0;
        for(int j = 0; j < v.size(); ++j){
            if(j != 0)
                ans += v[j].second * sum;
            sum += v[j].first;
        }
    }
    cout << ans << '\n';
}

int main(){
    fast;
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
