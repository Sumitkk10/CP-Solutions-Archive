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
        ll n, cnt = 0, cnt1 = 0;
        cin >> n;
        ll a[n], b[n], ans[n];
        for(int i = 0; i < n; ++i){
            cin >> a[i];
        }
        for(int i = 0; i < n; ++i){
            cin >> b[i];
        }
        for(int i = 0; i < n; ++i){
            if(a[i] <= b[i]) cnt++;
        }
        ll j = 1;
        for(int i = 0; i < n; ++i){
            ans[i] = a[n-j];
            j++;
        }
        for(int i = 0; i < n; ++i){
            if(ans[i] <= b[i]) cnt1++;
        }
        if(cnt == n && cnt1 == n) cout << "both\n";
        else if(cnt == n && cnt1 != n) cout << "front\n";
        else if(cnt != n && cnt1 == n) cout << "back\n";
        else cout << "none\n";
    }
    return 0;
}