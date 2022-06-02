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
        ll n, c = 1, mx = 0, d = 0;
        cin >> n;
        vector<ll> a(n), diff(n);    
        for(int i = 0; i < n; ++i)
            cin >> a[i];
        // sort(a.begin(), a.end());
        diff[0] = 1;
        for(int i = 1; i < n; ++i){
            if(a[i] - a[i-1] <= 2)
                diff[i] = diff[i-1]+1;
            else
                diff[i] = 1;
            if(diff[i] > mx)
                mx = diff[i];
        }
        ll min = 100000001;
        for(int i = 0; i < n; ++i){
            ll k = i;
            for(int j = i+1; j < n; ++j){
                if(a[j] - a[k] <= 2)
                    ++c;
                else{
                    i = j-1;
                    break;
                }
                if(j == n-1){
                    ++d;
                    break;
                }
                ++k;
            }
            if(c < min)
                min = c;
            c = 1;
            if(d > 0)
                break;
        }
        cout << min << ' ' << mx << '\n';
    }
    return 0;
}
//                              This_Code_Is_Written_By_Sumit!!