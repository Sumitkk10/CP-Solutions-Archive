#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define vii vector<ll> 
#define pb push_back
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 7, N = 1e4 + 3;

int main(){
    fast;
    ll t;
    cin >> t;
    cin.ignore();
    while(t--){
        string s;
        getline(cin, s);
        for(int i = 0; i < s.size(); ++i){
            if(s[i] != ' ')
                s[i] = tolower(s[i]);
        }
        string a = "berhampore";
        string b = "serampore";
        if(s.find(a) != string::npos){
            if(s.find(b) != string::npos) cout << "Both\n";
            else cout << "GCETTB\n";
        }
        else if(s.find(b) != string::npos) cout << "GCETTS\n";
        else cout << "Others\n";
    }
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
    return 0;
}