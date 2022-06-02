#include<bits/stdc++.h>
#define ll long long int
#define ld long double
using namespace std;

int main(){
    ll t;
    cin >> t;
    while(t--) {
        ll n, m;
        cin >> n >> m;
        if(m < 9)
            cout << 0 << ' ' << 0 << '\n';
        else{
            ll a = 9, ans = 0, b = 0;
            while(a <= m){
                ans += n;
                b = a;
                string s = to_string(a);
                s.push_back('9');
                a = stoll(s);
            }
            cout << ans << ' ' << n << '\n';
        }
    }     
    return 0;
}