#include <bits/stdc++.h>
#define ll long long int    
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const ll MOD = 1e9 + 7, N = 1e5 + 3;

int main(){
    ll n;
    cin >> n;
    ll a[n], b[n], prefix_sum[n], suffix_sum[n], mx = 0;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    for(int i = 0; i < n; ++i){
        cin >> b[i];
        if(i == 0)
            prefix_sum[i] = b[i];
        else
            prefix_sum[i] = prefix_sum[i-1] + b[i];
    }
    suffix_sum[n-1] = b[n-1];
    for(int i = n-2; i >= 0; --i)
        suffix_sum[i] = suffix_sum[i+1] + b[i];
    ll diff[n], diff1[n];
    for(int i = 0; i < n; ++i){
        if(i == 0) diff[i] = a[i] - prefix_sum[i];
        else diff[i] = max(diff[i-1], a[i] - prefix_sum[i]);
    }
    for(int i = 0; i < n; ++i){
        if(i == 0) diff1[i] = a[i];
        else diff1[i] = max(diff1[i-1], prefix_sum[i-1] + a[i]);
    }
    for(int i = 1; i < n; ++i){
        ll sum = prefix_sum[i-1] + a[i];
        mx = max(mx, sum + diff[i-1]);
    }
    for(int i = 1; i < n; ++i){
        ll sum;
        if(i == n - 1) sum = a[i];
        else
            sum = suffix_sum[i + 1] + a[i];
        mx = max(mx, sum + diff1[i - 1]);
    }
    cout << mx;
    return 0;
}