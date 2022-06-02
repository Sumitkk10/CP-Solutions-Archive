#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int> > a;
    for(int i = 1; i <= n*m; ++i){
        int x, y;
        cin >> x >> y;
        a.push_back({x, y});
    }
    int low = 0, high = n*m - 1, ans = -1;
    while(low <= high){
        int mid = (low + high) / 2;
        int temp[n + 1][m + 1], pre[n + 1][m + 1];
        memset(temp, 0, sizeof temp);
        memset(pre, 0, sizeof pre);
        for(int i = 0; i <= mid; ++i){
            if(i % 2) temp[a[i].first][a[i].second] = -1;
            else temp[a[i].first][a[i].second] = 1;
        }
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j)
                pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + temp[i][j];
        bool ok = 0, okk = 0;
        for(int i = k; i <= n; ++i){
            for(int j = k; j <= m; ++j){
                int x1 = i - k + 1, x2 = j - k + 1;
                int cnt = pre[i][j] - pre[x1 - 1][j] - pre[i][x2 - 1] + pre[x1 - 1][x2 - 1];
                if(cnt == k*k)
                    ok = 1;
                else if(-cnt == k*k)
                    okk = 1;
            }
        }
        if(ok and okk){
            ans = 1;
            high = mid - 1;
            continue;
        }
        else if(ok){
            ans = 1;
            high = mid - 1;
        }
        else if(okk){
            ans = 2;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    if(ans == -1) cout << "Draw\n";
    else if(ans == 1) cout << "Alice\n";
    else cout << "Bob\n";
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
