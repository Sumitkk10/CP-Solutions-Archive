#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 9; 

int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        if(n == 1)
            cout << 1 << '\n';
        else{
            ll ans = n*n*n;
            ll ans1 = (n-2)*(n-2)*(n-2);
            cout << ans - ans1 << '\n';
        }
    }
    return 0;
}