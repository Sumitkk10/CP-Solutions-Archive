#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

ll highestpowerof2(ll n){ 
   ll p = log2(n);
   return (1 << p);
}

void solve(){
    long long int n, k;
    cin >> n >> k;
    long long int a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    if(n <= 2){
        int i = 0;
        while(k-- and i < n - 1){
            int x = highestpowerof2(a[i]);
            a[i] ^= x;
            bool ok = 0;
            for(int j = i + 1; j < n; ++j){
                if((a[j] ^ x) < a[j]){
                    ok = 1;
                    a[j] ^= x;
                    break;
                }
            }
            if(!ok)
                a[n - 1] ^= x;
            while(a[i] <= 0)
                ++i;
        }
        if(k >= 0)
            ++k;
        if(k % 2 == 1){
            a[n - 1] ^= 1;
            a[n - 2] ^= 1;
        }
        for(auto k : a)
            cout << k << ' ';
        cout << '\n';
        return;
    }
    int i = 0;
    while(k-- and i < n - 1){
        int x = highestpowerof2(a[i]);
        a[i] ^= x;
        bool ok = 0;
        for(int j = i + 1; j < n; ++j){
            if((a[j] ^ x) < a[j]){
                ok = 1;
                a[j] ^= x;
                break;
            }
        }
        if(!ok)
            a[n - 1] ^= x;
        while(a[i] <= 0)
            ++i;
    }
    for(int i = 0; i < n; ++i)
        cout << a[i] << ' ';
    cout << '\n';
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
