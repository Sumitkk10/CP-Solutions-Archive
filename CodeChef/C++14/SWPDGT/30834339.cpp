#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;


int main(){
    ll t;
    cin >> t;
    while(t--){
        ll a, b;
        cin >> a >> b;
        if(a < 10 && b < 10) cout << a + b << '\n';
        else if(a < 10 && b >= 10 || a >= 10 && b < 10){
            if(a < 10){
                ll ans = (((b/10)*10)+a)+(b%10);
                ll ans1 = (((a*10)+(b%10))+b/10);
                cout << max(ans, ans1) << '\n';
            }
            else if(b < 10){
                ll ans = (((a/10)*10)+b)+(a%10);
                ll ans1 = (((b*10)+(a%10))+(a/10));
                cout << max(ans, ans1) << '\n';
            }
        }
        else {
            ll ans = ((((b/10)*10) + a/10) + ((b%10)*10+a%10));
            ll ans1 = ((((a/10)*10) + b/10) + ((a%10)*10+b%10));
            ll ans2 = ((((a/10)*10) + b%10) + ((b/10)*10+a%10));
            cout << max(ans, max(ans1, ans2)) << '\n';
        }
    }
    return 0;
}
