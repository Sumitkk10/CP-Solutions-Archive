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
        ll n, a, b, k;
        cin >> n >> a >> b >> k;
        ll ans = n/a;
        ans += n/b;
        ll lcm = (a*b)/__gcd(a,b);
        lcm = n/lcm;
        ll r = lcm*2;
        ans = ans-r;
        if(ans < k)
            cout << "Lose" << '\n';
        else
            cout << "Win" << '\n';
    }
    return 0;
}
//                              This_Code_Is_Written_By_Sumit!!