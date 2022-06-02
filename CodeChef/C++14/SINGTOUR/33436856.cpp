#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 7;

int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        pair<ll, ll> a[n], l[n], r[n];
        ll sol[n] = {0};
        for(int i = 0; i < n; ++i){
            cin >> a[i].first >> a[i].second;
            l[i].first = a[i].first;
            r[i].first = a[i].second;
            l[i].second = i;
            r[i].second = i;
        }
        sort(l, l + n);
        sort(r, r + n, greater<>());
        for(int i = 0; i < n; ++i)
            sol[l[i].second] += n-(i+1);
        for(int i = 0; i < n; ++i)
            sol[r[i].second] += n-(i+1);
        for(int i = 0; i < n; ++i)
            cout << sol[i] << ' ';
        cout << '\n';
    }
    return 0;
}
 