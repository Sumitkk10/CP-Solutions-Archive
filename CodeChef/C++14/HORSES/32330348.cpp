#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int MOD = 1e9 + 7;

int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n, diff, min = 100000000001;
        cin >> n;
        vector<ll> a(n);
        for(int i = 0; i < n; ++i)
            cin >> a[i];
        for(int i = 0; i < n-1; ++i){
            for(int j = i + 1; j < n; ++j){
                diff = abs(a[i] - a[j]);
                if(diff < min)
                    min = diff;
            }
        }
        cout << min << '\n';
    }
    return 0;
}
