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
        ll n, ans = 0, x = 1;
        cin >> n;
        string s;
        cin >> s;
        for(int i = 0; i < n; ++i){
            if(s[i] == '1'){
                ans += x;
                ++x;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}