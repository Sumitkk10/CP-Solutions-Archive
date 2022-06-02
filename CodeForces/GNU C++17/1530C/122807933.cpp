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
    long long int a[n + 1], b[n + 1];
    for(long long int i = 1; i <= n; ++i)
        cin >> a[i];
    for(long long int j = 1; j <= n; ++j)
        cin >> b[j];
    sort(a + 1, a + n + 1, greater<long long int>());
    sort(b + 1, b + n + 1, greater<long long int>());
    long long int req = n - (n/4);
    long long int pre_sum[n + 1], pre_sum1[n + 1];
    pre_sum[0] = 0;
    pre_sum1[0] = 0;
    for(long long int i = 1; i <= n; ++i){
        pre_sum[i] = pre_sum[i - 1] + a[i];
        pre_sum1[i] = pre_sum1[i - 1] + b[i];
    }
    for(int i = 0; i <= n; ++i){
        int rounds = n + i;
        rounds = rounds - (rounds / 4);
        long long cur = 100*min(rounds, i);
        rounds -= min(rounds, i);
        cur += pre_sum[rounds];
        if(cur >= pre_sum1[min(n, (n + i) - (n + i)/4)]){
            cout << i << '\n';
            return;
        }
    }
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
