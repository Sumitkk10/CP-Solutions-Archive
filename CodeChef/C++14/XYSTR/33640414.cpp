#include<bits/stdc++.h>
#define ll long long int
#define ld long double
using namespace std;
const int MOD = 1000000007, N = 8001, M = 61;

int main(){
    ll t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        ll ans = 0;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == 'x' && s[i+1] == 'y' || s[i] == 'y' && s[i+1] == 'x'){
                ++ans;
                ++i;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}