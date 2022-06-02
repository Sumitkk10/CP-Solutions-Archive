#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    int ans = 0;
    for(int i = 1; i <= n; ++i)
        cin >> a[i - 1];
    while(!is_sorted(a.begin(), a.end())){
        for(int i = ans % 2; i + 1 < n; i += 2)
            if(a[i] > a[i + 1])
                swap(a[i], a[i + 1]);
        ++ans;
    }
    cout << ans << "\n";
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
