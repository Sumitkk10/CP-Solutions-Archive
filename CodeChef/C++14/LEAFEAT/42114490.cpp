#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define pb push_back
using namespace std;
const int N = 20 + 5;
const int MOD = 1e9 + 7;
long long n, k, a[N], ans;

long long int go(int i, long long lcm, int size){
    if(i == k){
        if(size == 0)
            return 0;
        if(size % 2)
            ans += (1 + ((n - 1) / lcm));
        else
            ans -= (1 + ((n - 1) / lcm));
        return 0;
    }
    go(i + 1, lcm, size);
    go(i + 1, (a[i] * lcm) / __gcd(lcm, a[i]), size + 1);
    return 0;
}

int main(){
    fast;
    cin >> n >> k;
    for(int i = 0; i < k; ++i)
        cin >> a[i];
    go(0, 1, 0);
    cout << n - ans << "\n";
    return 0;
}