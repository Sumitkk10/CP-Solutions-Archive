#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
    string s;
    cin >> s;
    vector<int> odd, even;
    for(auto k : s){
        if((k - '0') % 2) odd.push_back(k - '0');
        else even.push_back(k - '0');
    }
    int i = 0, j = 0;
    while(i < odd.size() and j < even.size()){
        if(i < odd.size() and odd[i] < even[j]){
            cout << odd[i];
            ++i;
        }
        else{
            cout << even[j];
            ++j;
        }
    }
    while(i < odd.size()){
        cout << odd[i];
        ++i;
    }
    while(j < even.size()){
        cout << even[j];
        ++j;
    }
    cout << "\n";
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
