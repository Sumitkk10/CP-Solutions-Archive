#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
int n, a[N], k;

bool check(long long mid){
    int ans = 0;
    for(int i = 1; i <= n; ++i)
        ans += (a[i] / mid);
    return (ans >= k);
}

void solve(){
    cin >> n;
    long long sum = 0;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        sum += a[i];
    }
    sort(a + 1, a + n + 1);
    cin >> k;
    if(k >= sum){
    	cout << 0 << "\n";
    	return;
    }
    long long low = 1, high = a[1], ans = -1;
    while(low <= high){
        long long mid = (low + high) / 2;
        if(check(mid)){
            ans = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    cout << ans << "\n";
}

int main(){
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}
