#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 3005;
const int MOD = 1e9 + 7;
vector<int> arr;
int n, l, a[N];

bool is_possible(int cost){
    int dp[n + 1] = {0};
    dp[0] = 1;
    for(int i = 1; i < n; ++i){
        int mx = 0;
        for(int j = 0; j < i; ++j)
            if(abs(arr[j] - arr[i]) >= cost)
                mx = max(mx, dp[j]);
        dp[i] = mx + 1;
    }
    bool ok = 0;
    for(int i = 0; i < n; ++i)
        if(dp[i] >= l)
            ok = 1;
    return ok;
}

int main(){
    fast;
    int t;
    cin >> t;
    while(t--){
        cin >> n >> l;
        pair<int, int> b[n + 2];
        for(int i = 1; i <= n; ++i){
            cin >> a[i];
            b[i].first = a[i];
            b[i].second = i;
        }
        sort(b + 1, b + n + 1, greater<>());
        for(int i = 1; i <= n; ++i)
            arr.push_back(b[i].second);
        int low = 0;
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j)
                if(b[i].first == b[j].first)
                    low = max(low, abs(b[i].second - b[j].second));
        int high = n - 1, ans = low;
        while(low <= high){
            int mid = (low + high) / 2;
            if(is_possible(mid)){
                ans = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        cout << ans << '\n';
        arr.clear();
    }
    return 0;
}
