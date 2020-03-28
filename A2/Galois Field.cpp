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

// A*B % C
string division(string A, string B, string C) {
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());
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
        return p_x.substr(p_x.length() - 8);
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
    return p_x.substr(p_x.length() - 8);
}

string hexToBinary(string s){ 
      unordered_map<char, string> dict1; 
      dict1['0']= "0000"; 
      dict1['1']= "0001"; 
      dict1['2']= "0010"; 
      dict1['3']= "0011"; 
      dict1['4']= "0100"; 
      dict1['5']= "0101"; 
      dict1['6']= "0110"; 
      dict1['7']= "0111"; 
      dict1['8']= "1000"; 
      dict1['9']= "1001"; 
      dict1['A']= "1010"; 
      dict1['B']= "1011"; 
      dict1['C']= "1100"; 
      dict1['D']= "1101"; 
      dict1['E']= "1110"; 
      dict1['F']= "1111"; 

      string binary = ""; 
      for(char c : s){ 
            binary += dict1[c];
      } 
      return binary; 
}

string binaryToHex(string s){ 
      unordered_map<string, char> dict1; 
      dict1["0000"] = '0';
      dict1["0001"] = '1';
      dict1["0010"] = '2';
      dict1["0011"] = '3';
      dict1["0100"] = '4';
      dict1["0101"] = '5';
      dict1["0110"] = '6';
      dict1["0111"] = '7';
      dict1["1000"] = '8';
      dict1["1001"] = '9';
      dict1["1010"] = 'A';
      dict1["1011"] = 'B';
      dict1["1100"] = 'C';
      dict1["1101"] = 'D';
      dict1["1110"] = 'E';
      dict1["1111"] = 'F';
      string hex = ""; 
      for(int i = 0; i < s.length(); i += 4) {
            hex += dict1[s.substr(i, 4)];
      }
      return hex;
}

void solution() {
    string m = "100011010";
    itr(i, 4) {
        string f, g; cin >> f >> g;
        string f1 = hexToBinary(f);
        string g1 = hexToBinary(g);
        string r_x = division(f1, g1, m);
        cout << binaryToHex(r_x) << endl;
    }
    // int i = 0;
    // for(; i < r_x.length(); ++i) {
    //     if(r_x[i] == '1') break;
    // }
    // return r_x;
}

int32_t main() {
    IOS;
    solution();
    // cout << solution();
    return 0;
}