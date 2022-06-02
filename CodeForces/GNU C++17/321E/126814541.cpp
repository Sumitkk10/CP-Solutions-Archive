#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 4005;
const int MOD = 1e9 + 7;
int n, k, a[N][N], pre_sum[N][N];
vector<int> dp_before(N), cur_dp(N);

int next_int() {
    char c;
    do {c = getchar();} while(c != '-' && !isdigit(c));
    bool neg = (c == '-');
    int result = neg ? 0 : c - '0';
    while(isdigit(c = getchar())) result = 10 * result + (c - '0');
    return neg ? -result : result;
}

int C(int x, int xx){
    ll ok = pre_sum[xx][xx];
    ok += pre_sum[x - 1][x - 1];
    ok -= pre_sum[x - 1][xx];
    ok -= pre_sum[xx][x - 1];
    return ok/2;
}

void compute(int l, int r, int optl, int optr){
    if (l > r)
        return;
    int mid = (l + r) >> 1;
    long long best = INT_MAX, idx;
    for (int i = optl; i < min(mid, optr + 1); i++) {
        if(i == mid) continue;
        if(best > dp_before[i] + C(i + 1, mid)){
            best = dp_before[i] + C(i + 1, mid);
            idx = i;
        }
    }
    cur_dp[mid] = best;
    compute(l, mid - 1, optl, idx);
    compute(mid + 1, r, idx, optr);
}

void solve(){
    n = next_int();
    k = next_int();
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            a[i][j] = next_int();
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            pre_sum[i][j] = a[i][j] + pre_sum[i - 1][j] + pre_sum[i][j - 1] - pre_sum[i - 1][j - 1];
    // let dp[i][k] be the min number of unfamiliar level if we group first i people in k groups.
    for(int i = 1; i <= n; ++i)
        dp_before[i] = C(1, i);
    for(int groups = 1; groups < k; ++groups){
        compute(1, n, 0, n - 1);
        dp_before = cur_dp;
    }
    cout << dp_before[n] << "\n";
}

int main(){
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}
