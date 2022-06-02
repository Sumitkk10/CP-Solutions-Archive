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
        ll n;
        cin >> n;
        ll a[n];
        for(int i = 0; i < n; ++i)
            cin >> a[i];
        if(n == 1)
            cout << 1 << '\n';
        else{
            ll ans = 1, cnt = 0;
            for(int i = 1; i < n; ++i){
                for(int j = 0; j < i; ++j){
                    if(a[i] > a[j])
                        break;
                    else if(a[i] < a[j])
                        cnt++;
                }
                if(cnt == i)
                    ans++;
                cnt = 0;
            }
            cout << ans << '\n';
        }
    }
    return 0;
} 