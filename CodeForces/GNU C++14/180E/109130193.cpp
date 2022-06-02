#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 2e5 + 5;
const int MOD = 1e9 + 7;
int n, m, k, col[N];
vector<pair<int, int> > pos[N];

int main(){
    fast;
    cin >> n >> m >> k;
    for(int i = 0; i < n; ++i)
        cin >> col[i];
    for(int i = 0; i < n; ++i){
        int x = col[i], ct = 0, j = i;
        while(col[i] == x){
            ++i;
            ++ct;
        }
        --i;
        pos[x].push_back({j, i});
    }
    int ans = 0;
    for(int i = 1; i <= m; ++i){
        if(pos[i].empty())
            continue;
        int pre_sum[pos[i].size()] = {0}, pre_sum1[pos[i].size()] = {0};
        int mx = pos[i][0].second - pos[i][0].first + 1;
        pre_sum1[0] = mx;
        for(int j = 1; j < pos[i].size(); ++j){
            pre_sum[j] = pre_sum[j - 1] + (pos[i][j].first - pos[i][j - 1].second - 1);
            pre_sum1[j] = pre_sum1[j - 1] + (pos[i][j].second - pos[i][j].first  + 1);
        }
        for(int j = 1; j < pos[i].size(); ++j){
            int low = 0, high = j - 1, ok = j;
            while(low <= high){
                int mid = (low + high) / 2;
                if(pre_sum[j] - pre_sum[mid] <= k){
                    ok = mid;
                    high = mid - 1;
                }
                else
                    low = mid + 1;
            }
            if(ok == 0)
                mx = max(mx, pre_sum1[j]);
            else
                mx = max(mx, pre_sum1[j] - pre_sum1[ok - 1]);
        }
        // cout << mx << '\n';
        ans = max(ans, mx);
    }
    cout << ans << "\n";
    return 0;
}
