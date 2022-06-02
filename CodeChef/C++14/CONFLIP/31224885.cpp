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
        ll g;
        cin >> g;
        for(int z = 0; z < g; ++z){
            ll i, n, q; 
            cin >> i >> n >> q;
            if(n%2 == 0 || i == q){
                cout << n/2 << '\n';
            }
            else{
                if(i != q)
                    cout << n/2 + 1 << '\n';
            }
        }
    }
    return 0;
} 