#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 2;
const int MOD = 1e9 + 7;
vector<int> ind[N];
vector<pair<int, int> > mp;

int main(){
    fast;
    long long int n, k;
    cin >> n >> k;    
    long long int a[n], ans = 0;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j){
            ll sum = a[i] + a[j];
            if(sum >= k) continue;
            mp.push_back({sum, j});
            ind[sum].push_back(i);
        }
    }
    for(int i = 0; i < mp.size(); ++i){
        ll left = k - (mp[i].first);
        int j = mp[i].second;
        if(ind[left].empty()) continue;
        int low = 0, cur = -1, high = ind[left].size() - 1;
        while(low <= high){
            int mid = (low + high) / 2;
            if(ind[left][mid] > j){
                cur = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        if(cur == -1) continue;
        ans += (ind[left].size() - cur);
    }
    cout << ans << '\n';
    return 0;
}
