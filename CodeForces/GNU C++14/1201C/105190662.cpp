#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
long long int n, a[N], k;

bool check(int median){
    long long int sum = 0;
    for(int i = n/2; i < n; ++i)
        sum += max(0ll, median - a[i]);
    return (sum <= k);
}

int main() {
    fast;
    cin >> n >> k;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n);
    long long int low = a[n / 2] - 1, high = INT_MAX, ans = -1;
    while(low <= high){
        long long int mid = (low + high) / 2;
        if(check(mid)) {
            low = mid + 1;
            ans = mid;
        }
        else
            high = mid - 1;
    }
    cout << ans << '\n';
    return 0;
}