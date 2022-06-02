#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

bool areRotations(string str1, string str2){
    if (str1.length() != str2.length())
        return false;
 
    string temp = str1 + str1;
    return (temp.find(str2) != string::npos);
}

void solve(){
    string a, b;
    cin >> a >> b;
    cout << (areRotations(a, b) ? "Peter needs rest.\n" : "Is Peter fine?\n");
}

int main(){
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}
