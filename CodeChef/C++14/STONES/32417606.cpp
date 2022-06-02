#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int MOD = 1e9 + 7;

int main(){
    ll t;
    cin >> t;
    while(t--){
        string a, b;
        cin >> a >> b;
        ll c = 0;
        for(int i = 0; i < b.size(); ++i){
            for(int j = 0; j < a.size(); ++j){
                if(b[i] == a[j]){
                    ++c;
                    break;
                }
            }
        } 
        cout << c << '\n';
    }
    return 0;
}
//                              This_Code_Is_Written_By_Sumit!!