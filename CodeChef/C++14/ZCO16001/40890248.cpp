#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main(){
    fast;
    ll n, k;
    cin >> n >> k;
    ll a[n], b[n], sum = 0, c[n], d[n];
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        c[i] = a[i];
    }
    for(int i = 0; i < n; ++i){
        cin >> b[i];
        d[i] = b[i];
    }
    sort(a, a + n);
    sort(b, b + n);
    sort(c, c + n);
    sort(d, d + n);
    ll ans = max(a[n - 1], b[n - 1]), ans1, ans2;
    for(int i = 0; i < k; ++i){
        sort(a, a + n);
        sort(b, b + n);
        if(a[0] < b[n-1])
            swap(a[0], b[n - 1]);
        else
            break;
    }
    sort(b, b + n);
    ans1 = b[n - 1];
    for(int i = 0; i < k; ++i){
        sort(c, c + n);
        sort(d, d + n);
        if(d[0] < c[n - 1])
            swap(d[0], c[n - 1]);
        else
            break;
    }
    sort(c, c+n);
    ans2 = c[n - 1];
    cout << ans + min(ans1, ans2);
    return 0;
}