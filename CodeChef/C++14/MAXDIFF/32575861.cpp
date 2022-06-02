#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main(){
    fast;
    ll t;
    cin >> t;
    while(t--){
        ll n, k, sum = 0, sum1 = 0;
        cin >> n >> k;
        vector<ll> a(n);
        for(int i = 0; i < n; ++i)
            cin >> a[i];
        sort(a.begin(), a.end());
        if(k>n-k)
            k=n-k;
        for(int i = 0; i < k; ++i)
            sum += a[i];
        for(int i = k; i < n; ++i)
            sum1 += a[i];
        cout << abs(sum1 - sum) << '\n';
    }
    return 0;
}