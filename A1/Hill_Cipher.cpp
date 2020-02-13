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


int num(char c) {
      return (c - 'A');
}

int det(int matrix[2][2]) {
      return matrix[0][0]*matrix[1][1] - matrix[0][1]*matrix[1][0];
}

int modInverse(int a, int m) 
{ 
      a = a%m; 
      REP(x, 1, m) if((a*x) % m == 1) return x; 
      return -1;
} 

void multiply(int mat1[][2],  int mat2[][2],  int res[][2]) 
{ 
      int i, j, k; 
      REP(i, 0, 2)
      REP(j, 0, 2) { 
            res[i][j] = 0; 
            REP(k, 0, 2) res[i][j] += mat1[i][k] *  mat2[k][j]; 
      } 
    return;
}

int mod(int a, int b) {
      if(a < 0) return (b + a%b)%b;
      return a%b;
}

int32_t main()
{
      string cipherText;
      cin >> cipherText;
      string ct1, ct2, pt1="TH", pt2="HE";
      cin >> ct1 >> ct2;
      int P[2][2] = {
            num('T'), num('H'),num('H'), num('E')
      };
      int C[2][2] = {
            num(ct1[0]), num(ct1[1]), num(ct2[0]), num(ct2[1])
      };
      int P_det = det(P);
      int P_det_inv = modInverse(P_det, 26);
      int P_Inv[2][2] = {
            P_det_inv*num('E'), -P_det_inv*num('H'), -P_det_inv*num('H'), P_det_inv*num('T')
      };
      REP(i, 0, 2) REP(j, 0, 2) P_Inv[i][j] = mod(P_Inv[i][j], 26);
      // K = P_Inv . C (mod 26)
      int K[2][2];
      multiply(P_Inv, C, K);
      REP(i, 0, 2) REP(j, 0, 2) K[i][j] = mod(K[i][j], 26);
      int K_det = det(K);
      int K_det_inv = modInverse(K_det, 26);
      int K_Inv[2][2] = {
            K_det_inv*K[1][1], -1*K_det_inv*K[0][1], -1*K_det_inv*K[1][0], K_det_inv*K[0][0]
      };
      REP(i, 0, 2) REP(j, 0, 2) K_Inv[i][j] = mod(K_Inv[i][j], 26);
      //////// Now use ciphertext to construct C and multiplity it with K_Inv and take 26 modulo
      int rows = cipherText.length()/2;
      int ind = 0;
      for(int i = 0; i < cipherText.length() - 1; i += 2) {
            int a = num(cipherText[i]);
            int b = num(cipherText[i+1]);
            int a_new = a*K_Inv[0][0]+b*K_Inv[1][0];
            int b_new = a*K_Inv[0][1]+b*K_Inv[1][1];
            a_new = a_new%26;
            b_new = b_new%26;
            cout << (char)(a_new+'A') << (char)(b_new+'A');
      }
}