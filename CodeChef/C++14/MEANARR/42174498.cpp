#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
using namespace std;
const int MOD = 1e9 + 7;
const int N = 1e6 + 5;
int n, k, a[N];
long long pre_sum[N];

bool possible(int str, int end){
    long long sum = pre_sum[end] - pre_sum[str - 1];
    long double avr = (long double) sum / (end - str + 1);
    return (avr < k);
}

void solve() {
    cin >> n >> k;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        pre_sum[i] = pre_sum[i - 1] + a[i];
    }
    long long ans = 0;
    for(int i = 1; i <= n; ++i){
        int low = i, high = n, ok = -1;
        while(low <= high){
            int mid = (low + high) / 2;
            if(possible(i, mid)) {
                ok = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        if(ok == -1) continue;
        ans += ok - i + 1;
    }
    cout << ans << "\n";
}

int main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}