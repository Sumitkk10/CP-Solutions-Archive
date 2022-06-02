#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
    string s;
    cin >> s;
    int n = s.size();
    map<int, vector<int> > pos;
    for(int i = 0; i < n; ++i)
        pos[s[i] - 'a'].push_back(i);
    long long int ans = 0;
    for(auto k : pos)
        ans = max(ans, (ll) k.second.size());
    for(int i = 0; i < 26; ++i){
        for(int j = 0; j < 26; ++j){
            long long int mx = 0;
            for(auto k : pos[i]){
                int low = 0, high = pos[j].size() - 1, ans1 = -1;
                while(low <= high){
                    int mid = (low + high) / 2;
                    if(pos[j][mid] > k){
                        ans1 = mid;
                        high = mid - 1;
                    }
                    else
                        low = mid + 1;
                }
                if(ans1 == -1) continue;
                mx += (pos[j].size() - ans1);
            }
            ans = max(ans, mx);
        }
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
