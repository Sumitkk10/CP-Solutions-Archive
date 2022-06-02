#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int MOD = 1e9 + 7;

int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n, mx =  0, min = 10000001;
        cin >> n;
        vector<ll> a(n);
        for(int i = 0; i < n; ++i)
            cin >> a[i];
        for(int i = 0; i < n; ++i){
            ll c = 1;
            ll r = i;
            for(int j = i+1; j < n; j++){
                if(j-r == 1)
                    continue;
                if(a[i] == a[j]){
                    ++c;
                    r = j;
                }
            }
            if(c >= mx){
                // cout << c << ' ';
                // cout <<  min << ' ';
                if(c == mx || i == 0){
                    if(a[i] < min)
                        min = a[i];
                }
                else if(c > mx)
                    min = a[i];
                mx = c;
            }
        }
        cout << min << '\n';
    }
    return 0;
}
//                              This_Code_Is_Written_By_Sumit!!