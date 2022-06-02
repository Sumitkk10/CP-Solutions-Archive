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
        ll n, max = 0, ans = 0;
        cin >> n;
        for(int i = 0; i < n; ++i){
            ll s, v, p;
            cin >> s >> p >> v;
            s += 1;
            ans = (p/s)*v;
            if(ans > max)
                max = ans;
        }
        cout << max << '\n';
    }
    return 0;
}