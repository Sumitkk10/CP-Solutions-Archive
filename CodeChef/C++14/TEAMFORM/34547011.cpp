#include<bits/stdc++.h>
#define ll long long int
#define ld long long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 7, N = 2e5+5;

int main(){
    fast;
    ll t;
    cin >> t;
    while(t--){
        ll n, m;
        cin >> n >> m;
        pair<ll, ll> a[m];
        for(int i = 0; i < m; ++i)
            cin >> a[i].first >> a[i].second;
        m *= 2;
        n -= m;
        if(n%2 == 0)
            cout << "yes\n";
        else
            cout << "no\n";
    }
    return 0;
}