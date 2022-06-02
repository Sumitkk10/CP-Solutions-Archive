#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

ll add(ll a, ll b){
    return((a % MOD + b % MOD) % MOD);
}

ll mul(ll a, ll b){
    return(((a % MOD) * (b % MOD)) % MOD);
}

void solve(){
    int n;
    cin >> n;
    long long int a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    int cnt[62]= {0};
    for(int i = 0; i < n; ++i){
        long long int x = 1;
        for(int masks = 0; masks < 61; ++masks){
            if(a[i] & x)
                cnt[masks]++;
            x *= 2;
        }
    }
    long long int ans = 0;
    for(int j = 0; j < n; ++j){
        long long int orr = 0, andd = 0, x = 1;
        for(int masks = 0; masks < 61; ++masks){
            if(a[j] & x){
                orr = add(orr, mul(x, n));
                andd = add(andd, mul(x, cnt[masks]));
            }
            else
                orr = add(orr, mul(x, cnt[masks]));
            x *= 2;
        }
        ans = add(ans, mul(andd, orr));
    }
    cout << ans << '\n';
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();    
    return 0;
}
