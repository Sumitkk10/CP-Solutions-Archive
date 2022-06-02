#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int MOD = 1e9 + 7;

int main(){
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    for(int i = 0; i < n; ++i)
        cin >> b[i];
    ll min0 = 1000000001, min1 = 10000000001, min3 = 1000000001;
    for(int i = 0; i < n; ++i){
        if(b[i] == 1){
            if(a[i] < min0)
                min0 = a[i];
        }
        if(b[i] == 2){
            if(a[i] < min1)
                min1 = a[i];
        }
        if(b[i] == 3){
            if(a[i] < min3)
                min3 = a[i];
        }
    }
    cout << min(min3, (min0+min1));
    return 0;
}
