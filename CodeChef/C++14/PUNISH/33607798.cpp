#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define endl '\n'
using namespace std;

int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n, k;
        cin >> n >> k;
        if(k <= n)
            cout << k << endl;
        else{
            ll a = k - n;
            ll ans = (a/(n-1)) + 1;
            ll sum = n + ((n-1)*(ans-1));
            // cout << sum << ' ';
            if(ans%2 == 0){
                cout << k - sum + 1 << endl;
                continue;
            }     
            else
                cout << n - (k - sum) << endl;
        }
    }
    return 0;
}