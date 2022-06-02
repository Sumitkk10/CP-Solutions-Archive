#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main(){
    fast;
    ll n;
    cin >> n;
    ll s[n], w[n], sum[n], sum1[n];
    pair<ll, ll> lead[n]; // it will contain the leads at every point and the player with lead 
    for(int i = 0; i < n; ++i){
        cin >> s[i] >> w[i];
        if(i > 0){
            sum[i] = s[i] + sum[i-1];
            sum1[i] = w[i] + sum1[i-1];
        }
        else{
            sum[i] = s[i];
            sum1[i] = w[i];
        } 
    }
    for(int i = 0; i < n; ++i){
        // cout << sum[i] << ' ' << sum1[i] << '\n';
        if(sum[i] > sum1[i]){
            lead[i].second = 1;
            lead[i].first = sum[i] - sum1[i]; 
        }
        else if(sum1[i] > sum[i]){
            lead[i].second = 2;
            lead[i].first = sum1[i] - sum[i]; 
        }
    }
    sort(lead, lead+n);
    cout << lead[n-1].second << ' ' << lead[n-1].first; 
    return 0;
}
//                                     #!!{*[$um1t_Kum@r]*}!!#