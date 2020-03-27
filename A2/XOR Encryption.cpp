/*
      @author: Charan Sai
*/
#include <bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define int long long
#define itr(i, n) for(int i = 0; i < n; ++i)
#define itr1(i, a, n) for(int i = a; i < n; ++i)
#define INF 1e9 + 5
#define pb push_back 
#define ppi pair<int, int>
#define endl "\n"
#define nl cout << "\n"
// For Debugging
#define deb(x) cout << #x << " " << x << endl;

int hex_to_int(char a){
    if(a >= '0' && a <= '9') return (a - 48);
    else if(a >= 'A' && a <= 'Z') return(a - 55);
    return(a - 87);
}

string xor_hex_strings(string str1, string str2){
    stringstream xored_string;
    itr(i, str2.length()) {
        xored_string << hex << (hex_to_int(str1[i]) ^ hex_to_int(str2[i]));
    }
    return xored_string.str();
}

string get_string(char x) {
    string str(1, x);
    return str;    
} 

string solution() {
    string str; cin >> str;
    int n = str.length();
    string plain_text = "";
    plain_text += get_string(str[0]);
    itr1(i, 1, (n+1)/2) {
        // cout << str[i] << " " << plain_text[i-1] << endl;
        plain_text += xor_hex_strings(get_string(str[i]), get_string(str[i-1]));
    }
    return plain_text;
}
int32_t main() {
    cout << solution();
    return 0;
}