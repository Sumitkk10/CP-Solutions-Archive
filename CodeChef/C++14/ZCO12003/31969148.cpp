#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main(){
    fast;
    ll n, ans = 0, max = 0, max1 = 0, max2 = 0, ans1 = 0;
    cin >> n;
    ll s[n], c = 0, cnt = 0;
    for(int i = 0; i < n; ++i)
        cin >> s[i]; // a.push({s[i],})
    stack<pair<ll,ll> > a;
    for(int i = 0; i < n; ++i){
        if(s[i] == 2){
            ans = ((i-a.top().first)+1);
            a.pop();
        }
        else if(s[i] == 4){
            ans1 = ((i-a.top().first)+1);
            a.pop();
        }
        else if(a.empty() == true){
            a.push({i,1});
        }
        else{
            if(s[a.top().first] == s[i])
                a.push({i, a.top().second});
            else
                a.push({i, a.top().second + 1});
        }
        if(a.size() != 0)
            c = a.top().second;
        if(c>max)
            max = c;
        if(ans > max1)
            max1 = ans;
        if(ans1 > max2)
            max2 = ans1;
    }
    cout << max << ' ' << max1 << ' ' << max2;
    return 0;
}
//                                     #!!{*[$um1t_Kum@r]*}!!#
