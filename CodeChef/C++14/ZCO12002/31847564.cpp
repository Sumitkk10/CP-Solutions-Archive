#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
 
int main(){
    fast;
    ll n, x, y;
    cin >> n >> x >> y;
    pair<ll, ll> a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i].first >> a[i].second;
    ll b[x], c[y];
    for(int i = 0; i < x; ++i)
        cin >> b[i];
    for(int i = 0; i < y; ++i)
        cin >> c[i];
    sort(b, b+x);
    sort(c, c+y);
    sort(a, a+n);
    ll flg = 0, ans = 0, ans1 = 0, flg1 = 0, min = 100000000001, realans, realmin = 100000000001;
    for(int i = 0; i < n; ++i){
        int high = x-1;
        int low = 0;
        while(low <= high){
            int mid = (high+low)/2;
            if(b[mid] > a[i].first){
                high = mid-1;
            }
            else if(b[mid] <= a[i].first){
                ans = b[mid];
                flg++;
                low = mid+1;
            }
        }
        if(flg > 0){
            int hgh = y-1;
            int lw = 0;
            while(lw <= hgh){
                int md = (lw+hgh)/2;
                if(c[md] >= a[i].second){
                    ans1 = c[md];
                    flg1++;
                    hgh = md-1;
                }
                else if(c[md] < a[i].second){
                    lw = md+1;
                }
            }
        }
        if(flg > 0 && flg1 > 0){
            realans = (ans1 - ans)+1;
            if(realans < realmin)
                realmin = realans;
        }
        flg = 0;
        flg1 = 0;
    }
    cout << realmin;
    return 0;
}
//                                     #!!{*[$um1t_Kum@r]*}!!#