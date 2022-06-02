#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main(){
    fast;
    ll n, ans = 0;
    cin >> n;
    while(n--){
        ll x1, x2, x3, y2, y1, y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        ll distance = ((x2 - x1) * (x2 - x1)) + ((y2 - y1)*(y2 - y1));
        ll distance1 = ((x3 - x1) * (x3 - x1)) + ((y3 - y1)*(y3 - y1));
        ll distance2 = ((x2 - x3) * (x2 - x3)) + ((y2 - y3)*(y2 - y3));
        if(distance+distance2 == distance1 || distance2+distance1 == distance || distance+distance1 == distance2)
            ++ans;
    }
    cout << ans;
    return 0;
}