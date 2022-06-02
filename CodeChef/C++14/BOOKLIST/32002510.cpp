#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main(){
    fast;
    ll n;
    cin >> n;
    ll m, a[n+1];
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    cin >> m;
    ll b[m+1];
    for(int i = 1; i <= m; ++i){
        cin >> b[i];
    }
    for(int i = 1; i <= m; ++i){
        cout << a[b[i]] << '\n';
        for(int j = b[i]; j < n; ++j)
            a[j] = a[j+1];
    }
    return 0;
}
//                                     #!!{*[$um1t_Kum@r]*}!!#
