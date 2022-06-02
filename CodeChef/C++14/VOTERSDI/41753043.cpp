#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 7;
const int N = 1e6 + 5;

int main(){
    fast;
    int a, b, c;
    cin >> a >> b >> c;
    map<int, int> mp;
    for(int i = 0; i < a + b + c; ++i){
        int x;
        cin >> x;
        mp[x]++;
    }
    vector<int> ans;
    for(auto k : mp)
        if(k.second >= 2)
            ans.push_back(k.first);
    cout << ans.size() << '\n';
    for(auto k : ans)
        cout << k << '\n';
    return 0;
}