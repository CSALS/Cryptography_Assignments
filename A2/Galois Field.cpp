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

int char2int(char c) {
    if(c == '0') return 0;
    if(c == '1') return 1;
    return -1;
}

string get_string(char x) {
    string str(1, x);
    return str;    
}

char int2char(int x) {
    if(x == 0) return '0';
    if(x == 1) return '1';
    return '-';
}

int degree(string str) {
    int res;
    itr(i, str.length()) {
        if(str[i] == '1') {
            res = str.length() - i;
            break;
        }
    }
    return res;
}

string leftShitOne(string s) {
      char temp = s[0];
      for(int i = 0; i < s.length() - 1; ++i) s[i] = s[i + 1];
      s[s.length() - 1] = '0';
      return s;
}

string subtract_binary(string a, string b) {
    string res = "";
    itr(i, a.length()) {
        if(a[i] == '0') {
            if(b[i] == '0') res += "0";
            else if(b[i] == '1') res += "1";
        }
        else if(a[i] == '1') {
            if(b[i] == '0') res += "1";
            else if(b[i] == '1') res += "0";
        }
    }
    return res;
}

string division(string A, string B, string C) {
    int m = A.length(), n = B.length();
    vector<int> prod(m + n - 1); // Will have f(x) * g(x)
    itr(i, m + n - 1) prod[i] = 0;
    itr(i, m) {  
        itr(j, n) { 
            prod[i + j] += char2int(A[i]) * char2int(B[j]); 
        }
    }
    itr(i, m + n - 1) {
        prod[i] = prod[i] % 2;
    }
    reverse(prod.begin(), prod.end());
    string p_x = "";
    for(int num : prod) p_x += get_string(int2char(num));
    // Divide C by prod
    string m_x = C;
    if(degree(p_x) <= degree(m_x)) {
        return p_x;
    }
    int ct = degree(p_x) -  degree(m_x);
    while(ct--) {
         m_x = "0" + m_x;
    }
    // Perform Long Division
    while(degree(p_x) > degree(m_x)) {
        int ct = degree(p_x) -  degree(m_x);
        while(ct--) {
            m_x = leftShitOne(m_x);
        }
        // cout << m_x << endl;
        p_x = subtract_binary(p_x, m_x);
        // cout << p_x << endl;
    }
    return p_x;
} 

string solution() {
    string f, g, m; cin >> f >> g >> m;
    reverse(f.begin(), f.end());
    reverse(g.begin(), g.end());
    string r_x = division(f, g, m);
    int i = 0;
    for(; i < r_x.length(); ++i) {
        if(r_x[i] == '1') break;
    }
    return r_x.substr(i);
}

int32_t main() {
    IOS;
    
    cout << solution();
    return 0;
}