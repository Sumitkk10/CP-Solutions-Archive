#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
ll n, a[N];

long long int f(long long int x){
    long long int ans = 0;
    for(ll i = 0; i < n; ++i)
        ans += abs(a[i] - pow(x, i));
    return ans;
}

int main(){
    fast;
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n);
    long long int x = 1, ans = LLONG_MAX, oh = accumulate(a, a + n, 0ll) - n;
    while(true){
        if(pow(x, n - 1) > oh + a[n - 1])
            break;
        ans = min(ans, f(x));
        ++x;
    }
    cout << ans << '\n';
    return 0;
}
