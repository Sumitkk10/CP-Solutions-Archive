#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

long long highestPowerof2(long long int n){
    if (n < 1)
        return 0;
    int res = 1;
    for (int i = 0; i < 8*sizeof(unsigned int); i++)
    {
        int curr = 1 << i;
        // taken from gfg
        if (curr > n)
           break;
        res = curr;
    }
 
    return res;
}

void solve(){
    long long int n;
    cin >> n;
    cout << highestPowerof2(n) - 1 << '\n';
}

int main(){
    fast;
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
