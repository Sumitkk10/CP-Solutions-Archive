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
        char s[3][3];
        for(int i = 0; i < 3; ++i){
            for(int j = 0; j < 3; ++j){
                cin >> s[i][j]; 
            }
        }
        if(s[0][0] == 'l'){
            if(s[1][0] == 'l'){
                if(s[1][1] == 'l'){
                    cout << "yes\n";
                    continue;        
                }
            }
        }
        if(s[0][1] == 'l'){
            if(s[1][1] == 'l'){
                if(s[1][2] == 'l'){
                    cout << "yes\n";
                    continue;
                }
            }
        }
        if(s[1][0] == 'l'){
            if(s[2][0] == 'l'){
                if(s[2][1] == 'l'){
                    cout << "yes\n";
                    continue;
                }
            }
        }
        if(s[1][1] == 'l'){
            if(s[2][1] == 'l'){
                if(s[2][2] == 'l'){
                    cout << "yes\n";
                    continue;
                }
            }
        }
        cout << "no\n";
    }
    return 0;
}
