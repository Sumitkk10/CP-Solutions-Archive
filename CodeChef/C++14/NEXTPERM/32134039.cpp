#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
ll MOD = 15746;

int main(){
    fast;
    ll n, k;
    cin >> n >> k;
    ll a[n];
    while(k--){
        for(int i = 0; i < n; ++i)
            cin >> a[i];
        ll c = 0;
        for(int i = n-2; i >= 0; --i){
            for(int j = n-1; j > i; --j){
                if(a[j] > a[i]){
                    ++c;
                    swap(a[j], a[i]);
                    break;
                }
            }
            if(c > 0){
                sort(a+(i+1),a+n);
                break;
            }
        }
        for(int i = 0; i < n; ++i)
            cout << a[i] << ' ';
        cout << '\n';
    }
    return 0;
}
//                                     #!!{*[$um1t_Kum@r]*}!!#
