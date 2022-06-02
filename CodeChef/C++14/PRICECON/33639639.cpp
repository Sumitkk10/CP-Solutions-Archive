#include<bits/stdc++.h>
#define ll long long int
#define ld long double
using namespace std;
const int MOD = 1000000007, N = 8001, M = 61;

int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n, k;
        cin >> n >> k;
        ll a[n];
        for(int i = 0; i < n; ++i)
            cin >> a[i];
        ll sum = 0;
        for(int i = 0; i < n; ++i){
            if(a[i] > k)
                sum += a[i] - k;
        }
        cout << sum << '\n';
    }
    return 0;
}