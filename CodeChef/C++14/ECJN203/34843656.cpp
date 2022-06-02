#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define vii vector<ll> 
#define pb push_back
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 7, N = 2e5 + 3;

bool cmp(pair<pair<ll, ll>, ll> a, pair<pair<ll, ll>, ll> b){
     if(a.first.second != b.first.second){
        return a.first.second < b.first.second;
     }
     else if(a.first.first != b.first.first){
        return a.first.first > b.first.first;
     }
     else{
        return a.second > b.second;
     }
}

int main(){
    fast;
    ll n;
    cin >> n;
    pair<pair<ll, ll>, ll> a[n];
    ll idx[n];
    for(int i = 0; i < n; ++i){
        cin >> a[i].first.first >> a[i].first.second;
        a[i].second = i + 1;
    }
    sort(a, a+n, cmp);
    for(int i = 0; i < n; ++i){
        cout << a[i].second << ' ';
    }
    return 0;
}