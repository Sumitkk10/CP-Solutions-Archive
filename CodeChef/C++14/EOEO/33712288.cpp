#include<bits/stdc++.h>
#define ll long long int
#define ld long double
using namespace std;
const int MOD = 1000000007;

bool pow(ll n){ 
   if(n == 0) 
        return false; 
   return (ceil(log2(n)) == floor(log2(n))); 
} 

int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        if(n == 1 || n == 2 || pow(n)){
            cout << 0 << '\n';
            continue;
        }
        if(n%2 != 0){
            cout << n/2 << '\n';
            continue;
        }
        else{
            ll cnt = 0;
            ll b = n;
            while(b%2 == 0){
                ++cnt;
                b /= 2;
            }
            ll ans = 0;
            ll k = n / 2;
            if(k % 2 != 0)
                cout << n/4 << '\n';
            else{
                ++cnt;
                ll a = pow(2, cnt);
                ans = n/a;
                cout << ans << '\n';
            }
        }
    }
    return 0;
}