/*
      @author: Charan Sai
*/
#include <bits/stdc++.h>
#pragma GCC optimize ("-O3")
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define int long long
#define double long double
#define REP(i, a, n) for(int i = a; i < n; ++i)
#define INF 2000000000
#define pb push_back 
#define endl "\n"
#define nl cout << "\n"
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define diff(a,b) (a>b?a-b:b-a)
using namespace std;

int32_t main() {
      // Decrpyting cipher text of row transposition cipher
      int keylen; cin >> keylen;
      vector<int> key(keylen);
      REP(i, 0, keylen) cin >> key[i];
      REP(i, 0, keylen) key[i]--;
      string cipher_text; cin >> cipher_text;
      int cols = keylen;
      int rows = cipher_text.length()/keylen;
      char matrix[rows][cols];
      int index;
      for(int i = 0; i < cols; ++i) {
            index = key[i];
            for(int j = 0; j < rows; ++j) 
            matrix[j][i] = cipher_text[index*rows + j];
      }
      string vigenere_key = "";
      REP(i,0, rows) {
            REP(j, 0, cols) vigenere_key += matrix[i][j];
      }
      // Encrypt plain test using vigenere cipher
      string plain_text; cin >> plain_text;
      cipher_text = "";
      REP(i, 0, plain_text.length()) {
            cipher_text += char((plain_text[i]+vigenere_key[i%vigenere_key.length()] - 2*97)%26+97);
      }
      // Print results
      cout << vigenere_key << endl;
      cout << cipher_text;
      return 0;
}