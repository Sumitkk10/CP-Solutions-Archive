#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
    int n;
    cin >> n;
    int even = 0, odd = 0, a[n];
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        odd += (a[i] % 2);
        even += (a[i] % 2 == 0);
    }
    if(n == 1)
        cout << "0\n";
    else if(even == 0)
        cout << n << '\n';
    else if(odd == 0)  
        cout << n << '\n';
    else
        cout << min(odd + 2 * (even - 1), even + 2 * (odd - 1)) << '\n';    
}

int main(){
    fast;
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
