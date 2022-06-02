#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int main(){
    fast;
    ll t;
    cin >> t;
    while(t--){
        ll n, b, m;
        cin >> n >> b >> m;
        ll brak, sum = 0;
        while(n > 0){
            if(n%2 == 0) brak = n/2;
            else brak = (n+1)/2;
            if(brak == 0) brak++;
            sum += (m*brak);
            n -= brak;
            if(n == 0) 
                break;
            sum += b;
            m *= 2;
        }
        cout << sum << '\n';
    }
    return 0;
}