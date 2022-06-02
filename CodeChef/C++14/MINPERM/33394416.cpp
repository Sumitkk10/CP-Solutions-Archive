#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 7;

int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        ll a[n+1];
        a[0] = 0;
        for(int i = 1; i <= n; ++i)
            a[i] = i;
        for(int i = 1; i < n; i += 2)
            swap(a[i], a[i+1]);
        for(int i = 1; i <= n; ++i){
            if(a[i] == i)
                swap(a[i-1], a[i]);
        }
        for(int i = 1; i <= n; ++i)
            cout << a[i] << ' ';
        cout << '\n';
    }
    return 0;
}
