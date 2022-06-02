#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

bool isPerfectSquare(long double x)
{
    // Find floating point value of
    // square root of x.
    if (x >= 0) {
 
        long long sr = sqrt(x);
         
        // if product of square root
        //is equal, then
        // return T/F
        return (sr * sr == x);
    }
    // else return false if n<0
    return false;
}

void solve(){
    int n;
    cin >> n;
    int a[n];
    bool ok = 0;
    for(int i = 0; i < n; ++i){
    	cin >> a[i];
    	if(!isPerfectSquare(a[i]))
   			ok = 1;
    }
    cout << (ok ? "YES\n" : "NO\n");

}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}