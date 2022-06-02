#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
 
int main(){
    fast;
    ll n;
    cin >> n;
    while(n--){
        string s;
        cin >> s;
        int depth = 0, mx = 0;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == '<'){
                depth++;
            }
            else if(s[i] == '>'){
                depth--;
            }
            if(depth == 0)
                mx = max(mx, i+1);
            else if(depth < 0)
                break;
        }
        cout << mx << '\n';
    }
    return 0;
}