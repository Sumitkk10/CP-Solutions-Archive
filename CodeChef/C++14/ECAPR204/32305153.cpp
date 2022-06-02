#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int N = 1000000 + 5;

int main(){
    fast;
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<ll> a(n);
        map<ll, ll> hash;
        for(int i = 0; i < n; ++i){
            cin >> a[i];
            hash[a[i]]++;
        }
        for(auto i : hash){
            if(i.second > 0){
                cout << i.first << ":" << i.second << '\n'; 
            }
        }
    }
    return 0;
}
//                                     #!!{*[$um1t_Kum@r]*}!!#
