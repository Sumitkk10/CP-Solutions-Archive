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
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        ll ans = 0;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == s[i+1]){
                ++ans;
                ++i;
            }
            else
                ++ans;
        }
        cout << ans << endl;
    }
    return 0;
}