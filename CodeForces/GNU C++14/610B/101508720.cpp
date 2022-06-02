#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

int main(){
    fast;
    long long int n;
    cin >> n;
    long long int a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    long long int mn = *min_element(a, a + n);
    long long int ans = mn * n;
    for(int i = 0; i < n; ++i)
        a[i] -= mn;
    int cnt = 0, i = 0;
    while(a[i] > 0){
        ++i;
        ++cnt;
    }
    int k = i;
    i = n - 1;
    while(a[i] > 0){
        ++cnt;
        --i;
    }
    for(i = k; i < n; ++i){
        int ct = 0, j = i;
        while(a[i] > 0 and i < n){
            ++ct;
            ++i;
        }
        if(i != j)
            --i;
        cnt = max(cnt, ct);
    }
    cout << ans + cnt << '\n';
    return 0;
}
