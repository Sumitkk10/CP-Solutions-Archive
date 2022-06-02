#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;
set<long long int> pos;

void gen(vector<long long int> arr){
    if(arr.empty()) return;
    if(arr.size() == 1){
        pos.insert(arr[0]);
        return;
    }
    vector<long long int> l, r;
    long long int mid = (arr[0] + arr.back()) / 2, sum = 0; 
    for(int i = 0; i < arr.size(); ++i){
        if(arr[i] <= mid) l.push_back(arr[i]);
        else r.push_back(arr[i]);
        sum += arr[i];
    }
    pos.insert(sum);
    if(arr[0] == arr.back()) return;
    gen(l);
    gen(r);
}

void solve(){
    int n, q;
    cin >> n >> q;
    vector<long long int> a(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a.begin(), a.end());
    pos.clear();
    gen(a);
    while(q--){
        int x;
        cin >> x;
        if(pos.find(x) != pos.end())
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}   

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}