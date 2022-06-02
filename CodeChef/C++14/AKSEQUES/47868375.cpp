#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
long long n, a[N];

void solve(){
    cin >> n;
    long long ans = 1;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        if(a[i] % 2 == 0)
            ans *= 2;
    }
    long long tot = pow(3, n);
    cout << tot - ans << '\n'; 
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
