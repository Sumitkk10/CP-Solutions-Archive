#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define endl '\n'

using namespace std;

int main(){
    ll t, cnt = 0, cnt1 = 0;
    cin >> t;
    while(t--){
        ll s, n, k, l;
        cin >> s >> n >> k >> l;
        ll ans = 0;
        while(n--){
            ans += k;
            k *= l;
        }
        if(ans < s){
            cout << "POSSIBLE" << ' ' << s - ans << endl;
            cnt += s - ans;
        }
        else{
            cout << "IMPOSSIBLE" << ' ' << ans - s << endl; 
            cnt1 += ans - s;
        }
    }
    if(cnt >= cnt1)
        cout << "POSSIBLE";
    else
        cout << "IMPOSSIBLE"; 
    return 0;
}