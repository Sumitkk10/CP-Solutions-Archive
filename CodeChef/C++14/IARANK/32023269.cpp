#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main(){
    fast;
    ll n, cnt = 1;
    cin >> n;
    ll a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < i; ++j){
            if(a[i] < a[j])
                ++cnt;
        }
        cout << cnt << '\n';
        cnt = 1;
    }
    return 0;
}
//                                     #!!{*[$um1t_Kum@r]*}!!#
