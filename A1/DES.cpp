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

int PC1[56] = {
   57, 49, 41, 33, 25, 17,  9,
    1, 58, 50, 42, 34, 26, 18,
   10,  2, 59, 51, 43, 35, 27,
   19, 11,  3, 60, 52, 44, 36,
   63, 55, 47, 39, 31, 23, 15,
    7, 62, 54, 46, 38, 30, 22,
   14,  6, 61, 53, 45, 37, 29,
   21, 13,  5, 28, 20, 12,  4
};
 
int PC2[48] = {
    14, 17, 11, 24,  1,  5,
    3, 28, 15,  6, 21, 10,
    23, 19, 12,  4, 26,  8,
    16,  7, 27, 20, 13,  2,
    41, 52, 31, 37, 47, 55,
    30, 40, 51, 45, 33, 48,
    44, 49, 39, 56, 34, 53,
    46, 42, 50, 36, 29, 32
};
 
int IP[64] = {
    58, 50, 42, 34, 26, 18, 10,  2,
    60, 52, 44, 36, 28, 20, 12,  4,
    62, 54, 46, 38, 30, 22, 14,  6,
    64, 56, 48, 40, 32, 24, 16,  8,
    57, 49, 41, 33, 25, 17,  9,  1,
    59, 51, 43, 35, 27, 19, 11,  3,
    61, 53, 45, 37, 29, 21, 13,  5,
    63, 55, 47, 39, 31, 23, 15,  7
};
 
int Expansion[48] = {
    32,  1,  2,  3,  4,  5,  4,  5,
     6,  7,  8,  9,  8,  9, 10, 11,
    12, 13, 12, 13, 14, 15, 16, 17,
    16, 17, 18, 19, 20, 21, 20, 21,
    22, 23, 24, 25, 24, 25, 26, 27,
    28, 29, 28, 29, 30, 31, 32,  1}
;
 
int SBox[8][4][16] = {
     {
     {14,  4, 13,  1,  2, 15, 11,  8,  3, 10,  6, 12,  5,  9,  0,  7},
     { 0, 15,  7,  4, 14,  2, 13,  1, 10,  6, 12, 11,  9,  5,  3,  8},
     { 4,  1, 14,  8, 13,  6,  2, 11, 15, 12,  9,  7,  3, 10,  5,  0},
     {15, 12,  8,  2,  4,  9,  1,  7,  5, 11,  3, 14, 10,  0,  6, 13},
     },
 
     {
     {15,  1,  8, 14,  6, 11,  3,  4,  9,  7,  2, 13, 12,  0,  5, 10},
     { 3, 13,  4,  7, 15,  2,  8, 14, 12,  0,  1, 10,  6,  9, 11,  5},
     { 0, 14,  7, 11, 10,  4, 13,  1,  5,  8, 12,  6,  9,  3,  2, 15},
     {13,  8, 10,  1,  3, 15,  4,  2, 11,  6,  7, 12,  0,  5, 14,  9},
     },
 
     {
     {10,  0,  9, 14,  6,  3, 15,  5,  1, 13, 12,  7, 11,  4,  2,  8},
     {13,  7,  0,  9,  3,  4,  6, 10,  2,  8,  5, 14, 12, 11, 15,  1},
     {13,  6,  4,  9,  8, 15,  3,  0, 11,  1,  2, 12,  5, 10, 14,  7},
     { 1, 10, 13,  0,  6,  9,  8,  7,  4, 15, 14,  3, 11,  5,  2, 12},
     },
 
     {
     { 7, 13, 14,  3,  0,  6,  9, 10,  1,  2,  8,  5, 11, 12,  4, 15},
     {13,  8, 11,  5,  6, 15,  0,  3,  4,  7,  2, 12,  1, 10, 14,  9},
     {10,  6,  9,  0, 12, 11,  7, 13, 15,  1,  3, 14,  5,  2,  8,  4},
     { 3, 15,  0,  6, 10,  1, 13,  8,  9,  4,  5, 11, 12,  7,  2, 14},
     },
 
     {
     { 2, 12,  4,  1,  7, 10, 11,  6,  8,  5,  3, 15, 13,  0, 14,  9},
     {14, 11,  2, 12,  4,  7, 13,  1,  5,  0, 15, 10,  3,  9,  8,  6},
     { 4,  2,  1, 11, 10, 13,  7,  8, 15,  9, 12,  5,  6,  3,  0, 14},
     {11,  8, 12,  7,  1, 14,  2, 13,  6, 15,  0,  9, 10,  4,  5,  3},
     },
 
     {
     {12,  1, 10, 15,  9,  2,  6,  8,  0, 13,  3,  4, 14,  7,  5, 11},
     {10, 15,  4,  2,  7, 12,  9,  5,  6,  1, 13, 14,  0, 11,  3,  8},
     { 9, 14, 15,  5,  2,  8, 12,  3,  7,  0,  4, 10,  1, 13, 11,  6},
     { 4,  3,  2, 12,  9,  5, 15, 10, 11, 14,  1,  7,  6,  0,  8, 13},
     },
 
     {
     { 4, 11,  2, 14, 15,  0,  8, 13,  3, 12,  9,  7,  5, 10,  6,  1},
     {13,  0, 11,  7,  4,  9,  1, 10, 14,  3,  5, 12,  2, 15,  8,  6},
     { 1,  4, 11, 13, 12,  3,  7, 14, 10, 15,  6,  8,  0,  5,  9,  2},
     { 6, 11, 13,  8,  1,  4, 10,  7,  9,  5,  0, 15, 14,  2,  3, 12},
     },
 
     {
     {13,  2,  8,  4,  6, 15, 11,  1, 10,  9,  3, 14,  5,  0, 12,  7},
     { 1, 15, 13,  8, 10,  3,  7,  4, 12,  5,  6, 11,  0, 14,  9,  2},
     { 7, 11,  4,  1,  9, 12, 14,  2,  0,  6, 10, 13, 15,  3,  5,  8},
     { 2,  1, 14,  7,  4, 10,  8, 13, 15, 12,  9,  0,  3,  5,  6, 11},
     },
};
 
int PBox[32] = {
      16,  7, 20, 21, 29, 12, 28, 17,
       1, 15, 23, 26,  5, 18, 31, 10,
       2,  8, 24, 14, 32, 27,  3,  9,
      19, 13, 30,  6, 22, 11,  4, 25
};

string leftShitOne(string s) {
      char temp = s[0];
      for(int i = 0; i < s.length() - 1; ++i) s[i] = s[i + 1];
      s[s.length() - 1] = temp;
      return s;
}

string leftShiftTwo(string s) {
      return leftShitOne(leftShitOne(s));
}

string hexToBinary(string s){ 
      unordered_map<char, string> dict; 
      dict['0']= "0000"; 
      dict['1']= "0001"; 
      dict['2']= "0010"; 
      dict['3']= "0011"; 
      dict['4']= "0100"; 
      dict['5']= "0101"; 
      dict['6']= "0110"; 
      dict['7']= "0111"; 
      dict['8']= "1000"; 
      dict['9']= "1001"; 
      dict['A']= "1010"; 
      dict['B']= "1011"; 
      dict['C']= "1100"; 
      dict['D']= "1101"; 
      dict['E']= "1110"; 
      dict['F']= "1111"; 

      string binary = ""; 
      for(char c : s){ 
            binary += dict[c];
      } 
      return binary; 
}



string binaryToHex(string s){ 
      unordered_map<string, char> dict; 
      dict["0000"] = '0';
      dict["0001"] = '1';
      dict["0010"] = '2';
      dict["0011"] = '3';
      dict["0100"] = '4';
      dict["0101"] = '5';
      dict["0110"] = '6';
      dict["0111"] = '7';
      dict["1000"] = '8';
      dict["1001"] = '9';
      dict["1010"] = 'A';
      dict["1011"] = 'B';
      dict["1100"] = 'C';
      dict["1101"] = 'D';
      dict["1110"] = 'E';
      dict["1111"] = 'F';
      string hex = ""; 
      for(int i = 0; i < s.length(); i += 4) {
            hex += dict[s.substr(i, 4)];
      }
      return hex;
}

string xor_strings(string a, string b){ 
	string result = ""; 
	for(int i = 0; i < b.size(); ++i) result += (a[i] == b[i]) ? "0" : "1";
	return result; 
} 

int32_t main() {
      IOS;
      /* Shit Amount (Iteration -> Amount) */
      unordered_map<int, int> shift_amount;
      shift_amount[1] = 1;
      shift_amount[2] = 1;
      shift_amount[3] = 2;
      shift_amount[4] = 2;
      shift_amount[5] = 2;
      shift_amount[6] = 2;
      shift_amount[7] = 2;
      shift_amount[8] = 2;
      shift_amount[9] = 1;
      shift_amount[10] = 2;
      shift_amount[11] = 2;
      shift_amount[12] = 2;
      shift_amount[13] = 2;
      shift_amount[14] = 2;
      shift_amount[15] = 2;
      shift_amount[16] = 1;
      // Helper Data
      unordered_map<string, int> FourBitToDecimal; 
      FourBitToDecimal["0000"] = 0;
      FourBitToDecimal["0001"] = 1;
      FourBitToDecimal["0010"] = 2;
      FourBitToDecimal["0011"] = 3;
      FourBitToDecimal["0100"] = 4;
      FourBitToDecimal["0101"] = 5;
      FourBitToDecimal["0110"] = 6;
      FourBitToDecimal["0111"] = 7;
      FourBitToDecimal["1000"] = 8;
      FourBitToDecimal["1001"] = 9;
      FourBitToDecimal["1010"] = 10;
      FourBitToDecimal["1011"] = 11;
      FourBitToDecimal["1100"] = 12;
      FourBitToDecimal["1101"] = 13;
      FourBitToDecimal["1110"] = 14;
      FourBitToDecimal["1111"] = 15;
      unordered_map<int, string> DecimalToFourBit;
      DecimalToFourBit[0] = "0000";
      DecimalToFourBit[1] = "0001";
      DecimalToFourBit[2] = "0010";
      DecimalToFourBit[3] = "0011";
      DecimalToFourBit[4] = "0100";
      DecimalToFourBit[5] = "0101";
      DecimalToFourBit[6] = "0110";
      DecimalToFourBit[7] = "0111";
      DecimalToFourBit[8] = "1000";
      DecimalToFourBit[9] = "1001";
      DecimalToFourBit[10] = "1010";
      DecimalToFourBit[11] = "1011";
      DecimalToFourBit[12] = "1100";
      DecimalToFourBit[13] = "1101";
      DecimalToFourBit[14] = "1110"; 
      DecimalToFourBit[15] = "1111";
      //
      string plain_text, key_word; //both are 64bit
      cin >> plain_text;
      cin >> key_word;
      /* Convert hex to binary */
      plain_text = hexToBinary(plain_text);
      key_word = hexToBinary(key_word);
      /* Generate 56 bit DES key from 64 bit key word using PC1 table */
      string key = "";
      for(int i = 0; i < 56; ++i) key += key_word[PC1[i] - 1];
      // Generate round keys
      string left = key.substr(0, 28);
      string right = key.substr(28, 28);
      string first_key = "";
      for(int i = 1; i <= 16; ++i) {
            // Generate round key using PC-2 table
            string round_key = "";
            left = (shift_amount[i] == 1) ? leftShitOne(left) : leftShiftTwo(left);
            right = (shift_amount[i] == 1) ? leftShitOne(right) : leftShiftTwo(right);
            string combined = left + right;
            for(int j = 0; j < 48; ++j) round_key += combined[PC2[j] - 1];
            if(i == 1) first_key = round_key;
            cout << binaryToHex(round_key) << endl;
      }
      /* Calculating L1 = R0 and R1 = L0 ^ F(R0, K1) */
      
      // 1. PT(64) -> IP(PT) (64) using IP table
      string IP_Msg = "";
      for(int i = 0; i < 64; ++i) IP_Msg += plain_text[IP[i] - 1];
      string L0 = IP_Msg.substr(0, 32);
      string R0 = IP_Msg.substr(32, 64);
      // 2. L1 = R0
      string L1 = R0;
      // 3. Calculating F(R0, K1)
      // Round Function STARTS
      string expand_R0 = "";
      for(int i = 0; i < 48; ++i) expand_R0 += R0[Expansion[i] - 1];
      string intermediate = xor_strings(first_key, expand_R0);
      // intermediate (48 bit) passes through 8 S-boxes to get 32 bit quantity
	// Each 6 bit of the 48 bit will be use to lookup the corresponding S-box for the 4-bit number.
      int s_box_ind = 0;
      string result = "";
      for(int i = 0; i < 48; i += 6) {
            string six_bit = intermediate.substr(i, 6);
            string row_str = "";
            row_str += six_bit[0];
            row_str += six_bit[5];
            int row, col;
            if(row_str == "00") row = 0;
            else if(row_str == "01") row = 1;
            else if(row_str == "10") row = 2;
            else if(row_str == "11") row = 3;
            col = FourBitToDecimal[six_bit.substr(1, 4)];
            // S_Box[row][col] expressed in 4 bit is the compressed value
            result += DecimalToFourBit[SBox[s_box_ind++][row][col]];
      }
      string round_function = "";
      for(int i = 0; i < 32; ++i) round_function += result[PBox[i] - 1]; 
      // Round Function ENDS
      string R1 = xor_strings(L0, round_function);
      cout << binaryToHex(L1) << binaryToHex(R1) << endl;
      return 0;
}