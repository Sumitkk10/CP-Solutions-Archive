#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define vii vector<ll> 
#define pb push_back
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 7, N = 1e4 + 3;

int main(){
    fast;
    ll t;
    cin >> t;
    while(t--){
        ll n, k;
        cin >> n >> k;
        ll a = n/9, aa = k/9;
        if(a == aa || aa < a){
            if(k%9 == 0) cout << "1 " << aa << "\n";
            else
                cout << "1 " << aa + 1 << "\n";
        }
        else{
            if(n%9 == 0) cout << "0 " << a << "\n";
            else
                cout << "0 " << a + 1 << "\n";
        }
    }
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
    return 0;
}