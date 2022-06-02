#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
 
int main(){
    fast;
    ll n;
    cin >> n;
    ll a[n+1], cnt = 0, max = 0, ans = 0, max1 = 0, depth = 0, yo = 0, y = 1;
    for(int i = 1; i <= n; ++i){
        if(depth == 0){
            cnt = 0;
            y = i;
        }
        cin >> a[i];
        if(a[i] == 1)
            depth++;
        else 
            depth--;
        cnt++;
        if(depth > max){
            ans = i;
            max = depth;
        }
        if(cnt > max1){
            yo = y;
            max1 = cnt;
        }
    }
    cout << max << ' ' << ans << ' ' << max1<< ' ' << yo;
    return 0;
}