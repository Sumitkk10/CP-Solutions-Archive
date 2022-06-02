#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main(){
    fast;
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n+1);
    for(int i = 0; i <= n; ++i)
        a[i] = 0;
    while(k--){
        string s;
        cin >> s;
        if(s != "CLOSEALL"){
            ll x, ans = 0;
            cin >> x;
            if(a[x] == 0)
                a[x] = 1;
            else
                a[x] = 0;
            for(int i = 1; i <= n; ++i){
                if(a[i] == 1)
                    ++ans;
            }
            cout << ans << endl;
        }
        else{
            cout << 0 << endl;
            for(int i = 1; i <= n; ++i)
                a[i] = 0;
        }
    }
    return 0;
}