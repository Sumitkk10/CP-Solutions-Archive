#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int N = 402;

int main(){
    fast;
    ll t;
    cin >> t;
    while(t--){
        ll n, m, k;
        cin >> n >> m >> k;
        if(n == 1 && m == 1 || n == 2 && m == 1 || m == 2 && n == 1)
            cout << 0 << endl;
        else if(n == 1 || m == 1)
            cout << k << endl;
        else{
            if(k%2 == 0)
                cout << k/2 << endl;
            else
                cout << (k/2)+1 << endl;
        }
    }
    return 0;
}