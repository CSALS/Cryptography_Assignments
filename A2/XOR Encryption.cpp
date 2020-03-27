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

string solution() {
    string str; cin >> str;
    vector<string> xor_strings;
    int n = str.length();
    itr(i,n-1) str += "0";
    xor_strings.pb(str);
    itr(i, n-1) {
        int len = str.length();
        str.erase(str.begin() + len - 1);
        str = "0" + str;
        xor_strings.pb(str);
    }
    string xor_result = "";
    itr(i, str.length()) xor_result += "0";
    // for(string s : xor_strings) cout << s << endl;
    itr(i, xor_strings.size()) {
        xor_result = xor_hex_strings(xor_result, xor_strings[i]);
    }
    return xor_result;
}
int32_t main() {
    cout << solution();
    return 0;
}