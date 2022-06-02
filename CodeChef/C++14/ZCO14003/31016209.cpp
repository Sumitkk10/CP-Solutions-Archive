#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main(){
    fast;
    ll n;
    cin >> n;
    ll a[n], ans = 0, max = 0;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a+0, a+n);
    for(int i = 0; i < n; ++i){
        ans = a[i]*(n-i);
        if(ans > max)
            max = ans;
    }
    cout << max;
    return 0;
} 