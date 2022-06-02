#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define vii vector<ll> 
#define pb push_back
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 7, N = 1e4 + 3;

int main(){
    fast;
    ll t; 
    cin >> t;
    while(t--){
        ll n; cin >> n;
        string s;
        cin >> s;
        ll cnt0 = 0, cnt = 0, ct1 = 0, ct = 0;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == '1') ++cnt0;
            else cnt += cnt0;
        }
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == '0') ++ct1;
            else ct += ct1;
        }
        cout << cnt + ct << "\n";
    }
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
    return 0;
}