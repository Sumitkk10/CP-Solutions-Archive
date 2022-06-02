#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
vector<int> good = {4,8,15,16,23,42}, a(N);
int n;
map<int, int> mp;
map<int, vector<int> > pos;

void solve(){
    cin >> n;
    for(int i = 0; i < a.size(); ++i){
        cin >> a[i];
        mp[a[i]]++;
        pos[a[i]].push_back(i + 1);
    }
    if(n < 6){
        cout << n << '\n';
        return;
    }
    int mn = INT_MAX, ans = 0;
    for(auto k : good)
        mn = min(mn, mp[k]);
    // the min number of groups which i can make is mn.
    // but it may happen that the elements are not in order.
    map<int, int> cur;
    for(int i = 1; i <= mn; ++i){
        if(cur[0] >= pos[good[0]].size()){
            cout << n - 6 * (i - 1) << '\n';
            return;
        }
        int pre = pos[good[0]][cur[0]];
        for(int j = 1; j < good.size(); ++j){
            int low = cur[j], high = pos[good[j]].size() - 1, ans = -1;
            while(low <= high){
                int mid = (low + high) / 2;
                if(pos[good[j]][mid] > pre){
                    ans = mid;
                    high = mid - 1;
                }
                else
                    low = mid + 1;
            }
            if(ans == -1){
                cout << n - 6*(i - 1) << '\n';
                return;
            }
            cur[j] = ans + 1;
            pre = pos[good[j]][ans];
        }
        cur[0]++;
    }
    cout << n - 6*mn << '\n';

}

int main(){
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}
