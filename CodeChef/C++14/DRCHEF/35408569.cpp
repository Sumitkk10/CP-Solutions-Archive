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
        ll a[n];
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        sort(a, a+n);
        int idx = n;
        for(int i = 0; i < n; ++i){
            if(a[i] >= k){
                idx = i;
                break;
            }
        }
        int ans = 0;
        for(int i = idx; i < n; ++i){
            int cnt = 0;
            if(a[i] > k){
                while(k < a[i]){
                    ++cnt;
                    k *= 2;
                }
                ++cnt;
                ans += cnt;
            }
            else{
                ++cnt;
                ans += cnt;
            } 
            k = 2*a[i];
        }
      	if(idx == 0){
          	cout << idx + ans << "\n" ;
          	continue;
        }
     	int cnt = 0;
      	for(int i = idx - 1; i < n; ++i){
            if(a[i] > k){
                while(k < a[i]){
                    ++cnt;
                    k *= 2;
                }
                ++cnt;
            }
            else{
                ++cnt;
            } 
            k = 2*a[i];
        }
        cout << min(idx-1+cnt, idx + ans) << "\n"; 
    }
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
    return 0;
}