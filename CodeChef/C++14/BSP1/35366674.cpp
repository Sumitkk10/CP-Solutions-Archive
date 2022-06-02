#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define vii vector<ll> 
#define pb push_back
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 7, N = 1e6 + 1;
vii ans;

bool isPrime(int n){
    if(n == 1) return false;
    for(int i = 2; i <= sqrt(n); ++i) 
        if(n%i == 0) 
            return false;
    return true;
}

int main(){
    fast;
    ll t;
    cin >> t;
    ans.pb(0);
    for(int i = 1; i < N; ++i){
        ll x = ans.back();
        if(isPrime(i))
            ans.pb((x + i));
        else
            ans.pb(x);
    }
    while(t--){
        ll n;
        cin >> n;
        cout << ans[n] << "\n";
    }
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
    return 0;
}