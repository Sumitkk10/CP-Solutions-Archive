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
        ll i = 1, a = n, b = n, c = 0;
        while(b > 0){
            c++;
            b = b/10;
        }
        ll ans[c+1];
        ans[0] = 0;
        while(a > 0){
            ans[i] = a%10;
            a = a/10;
            ++i;
        }
        i = 1;
        while(n > 0){
            if(ans[i] == 0 && ans[i-1] != 0){
                cout << ans[i];
                ans[i] += 1;
            }
            else if(ans[i] != 0)
                cout << ans[i];
            n = n/10;
            ++i;
        }
        cout << '\n';
    }
    return 0;
} 