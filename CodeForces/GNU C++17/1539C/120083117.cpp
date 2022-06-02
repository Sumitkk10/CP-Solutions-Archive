#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
    long long n, k, x;
    cin >> n >> k >> x;
    long long a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n);
    vector<long long int> diff;
    for(int i = 1; i < n; ++i)
        diff.push_back(a[i] - a[i - 1]);
    sort(diff.begin(), diff.end());
    long long int i = 0;
    long long ans = 0;
    for(i = 0; i < diff.size(); ++i){
        if(diff[i] <= x) continue;
        if(k >= ((diff[i] - 1) / x))
            k -= ((diff[i] - 1) / x);
        else
            break;
    }
    cout << (diff.size() - i + 1) << '\n';
}

int main(){
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}
