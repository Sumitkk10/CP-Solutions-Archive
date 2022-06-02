#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int MOD = 1e9 + 7;

int main(){
    ll n;
    cin >> n;
    pair<ll, ll> a[n];
    vector<ll> sq(n), distinct;
    for(int i = 0; i < n; ++i){
        cin >> a[i].first >> a[i].second;
        sq[i] = min(a[i].first, a[i].second);
    }
    sort(sq.begin(), sq.end());
    for(int i = 0; i < n; ++i){
        if(i == 0 && i+1 < sq[i])
            sq[i] = i+1;
        else if(sq[i-1]+1 < sq[i])
            sq[i] = sq[i-1]+1;
    }
    for(int i = 0; i < n; ++i){
        // cout << sq[i] << ' ';
        if(distinct.empty() == true){
            distinct.push_back(sq[i]);
            continue;
        }
        if(sq[i] == sq[i-1]+1)
            distinct.push_back(sq[i]);
    }
    if(distinct[0] != 1)
        cout << 0;
    else
        cout << distinct.size();
    return 0;
}
//                                     #!!{*[$um1t_Kum@r]*}!!#