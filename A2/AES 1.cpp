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

const string S_Box[16][16] = {  
    {"63", "7C", "77", "7B", "F2", "6B", "6F", "C5", "30", "01", "67", "2B", "FE", "D7", "AB", "76"},  
    {"CA", "82", "C9", "7D", "FA", "59", "47", "F0", "AD", "D4", "A2", "AF", "9C", "A4", "72", "C0"},  
    {"B7", "FD", "93", "26", "36", "3F", "F7", "CC", "34", "A5", "E5", "F1", "71", "D8", "31", "15"},  
    {"04", "C7", "23", "C3", "18", "96", "05", "9A", "07", "12", "80", "E2", "EB", "27", "B2", "75"},  
    {"09", "83", "2C", "1A", "1B", "6E", "5A", "A0", "52", "3B", "D6", "B3", "29", "E3", "2F", "84"},  
    {"53", "D1", "00", "ED", "20", "FC", "B1", "5B", "6A", "CB", "BE", "39", "4A", "4C", "58", "CF"},  
    {"D0", "EF", "AA", "FB", "43", "4D", "33", "85", "45", "F9", "02", "7F", "50", "3C", "9F", "A8"},  
    {"51", "A3", "40", "8F", "92", "9D", "38", "F5", "BC", "B6", "DA", "21", "10", "FF", "F3", "D2"},  
    {"CD", "0C", "13", "EC", "5F", "97", "44", "17", "C4", "A7", "7E", "3D", "64", "5D", "19", "73"},  
    {"60", "81", "4F", "DC", "22", "2A", "90", "88", "46", "EE", "B8", "14", "DE", "5E", "0B", "DB"},  
    {"E0", "32", "3A", "0A", "49", "06", "24", "5C", "C2", "D3", "AC", "62", "91", "95", "E4", "79"},  
    {"E7", "C8", "37", "6D", "8D", "D5", "4E", "A9", "6C", "56", "F4", "EA", "65", "7A", "AE", "08"},  
    {"BA", "78", "25", "2E", "1C", "A6", "B4", "C6", "E8", "DD", "74", "1F", "4B", "BD", "8B", "8A"},  
    {"70", "3E", "B5", "66", "48", "03", "F6", "0E", "61", "35", "57", "B9", "86", "C1", "1D", "9E"},  
    {"E1", "F8", "98", "11", "69", "D9", "8E", "94", "9B", "1E", "87", "E9", "CE", "55", "28", "DF"},  
    {"8C", "A1", "89", "0D", "BF", "E6", "42", "68", "41", "99", "2D", "0F", "B0", "54", "BB", "16"}  
}; 
const string Rcon[10] = {"01000000", "02000000", "04000000", "08000000", "10000000",   
                 "20000000", "40000000", "80000000", "1B000000", "36000000"};

const string E_Table[16][16] = {
    {"01", "03", "05", "0F", "11", "33", "55", "FF", "1A", "2E", "72", "96", "A1", "F8", "13", "35"},
    {"5F", "E1", "38", "48", "D8", "73", "95", "A4", "F7", "02", "06", "0A", "1E", "22", "66", "AA"},
    {"E5", "34", "5C", "E4", "37", "59", "EB", "26", "6A", "BE", "D9", "70", "90", "AB", "E6", "31"},
    {"53", "F5", "04", "0C", "14", "3C", "44", "CC", "4F", "D1", "68", "B8", "D3", "6E", "B2", "CD"},
    {"4C", "D4", "67", "A9", "E0", "3B", "4D", "D7", "62", "A6", "F1", "08", "18", "28", "78", "88"},
    {"83", "9E", "B9", "D0", "6B", "BD", "DC", "7F", "81", "98", "B3", "CE", "49", "DB", "76", "9A"},
    {"B5", "C4", "57", "F9", "10", "30", "50", "F0", "0B", "1D", "27", "69", "BB", "D6", "61", "A3"},
    {"FE", "19", "2B", "7D", "87", "92", "AD", "EC", "2F", "71", "93", "AE", "E9", "20", "60", "A0"},
    {"FB", "16", "3A", "4E", "D2", "6D", "B7", "C2", "5D", "E7", "32", "56", "FA", "15", "3F", "41"},
    {"C3", "5E", "E2", "3D", "47", "C9", "40", "C0", "5B", "ED", "2C", "74", "9C", "BF", "DA", "75"},
    {"9F", "BA", "D5", "64", "AC", "EF", "2A", "7E", "82", "9D", "BC", "DF", "7A", "8E", "89", "80"},
    {"9B", "B6", "C1", "58", "E8", "23", "65", "AF", "EA", "25", "6F", "B1", "C8", "43", "C5", "54"},
    {"FC", "1F", "21", "63", "A5", "F4", "07", "09", "1B", "2D", "77", "99", "B0", "CB", "46", "CA"},
    {"45", "CF", "4A", "DE", "79", "8B", "86", "91", "A8", "E3", "3E", "42", "C6", "51", "F3", "0E"},
    {"12", "36", "5A", "EE", "29", "7B", "8D", "8C", "8F", "8A", "85", "94", "A7", "F2", "0D", "17"},
    {"39", "4B", "DD", "7C", "84", "97", "A2", "FD", "1C", "24", "6C", "B4", "C7", "52", "F6", "01"}
    };

const string L_Table[16][16] = {
    {"00", "00", "19", "01", "32", "02", "1A", "C6", "4B", "C7", "1B", "68", "33", "EE", "DF", "03"},
    {"64", "04", "E0", "0E", "34", "8D", "81", "EF", "4C", "71", "08", "C8", "F8", "69", "1C", "C1"},
    {"7D", "C2", "1D", "B5", "F9", "B9", "27", "6A", "4D", "E4", "A6", "72", "9A", "C9", "09", "78"},
    {"65", "2F", "8A", "05", "21", "0F", "E1", "24", "12", "F0", "82", "45", "35", "93", "DA", "8E"},
    {"96", "8F", "DB", "BD", "36", "D0", "CE", "94", "13", "5C", "D2", "F1", "40", "46", "83", "38"},
    {"66", "DD", "FD", "30", "BF", "06", "8B", "62", "B3", "25", "E2", "98", "22", "88", "91", "10"},
    {"7E", "6E", "48", "C3", "A3", "B6", "1E", "42", "3A", "6B", "28", "54", "FA", "85", "3D", "BA"},
    {"2B", "79", "0A", "15", "9B", "9F", "5E", "CA", "4E", "D4", "AC", "E5", "F3", "73", "A7", "57"},
    {"AF", "58", "A8", "50", "F4", "EA", "D6", "74", "4F", "AE", "E9", "D5", "E7", "E6", "AD", "E8"},
    {"2C", "D7", "75", "7A", "EB", "16", "0B", "F5", "59", "CB", "5F", "B0", "9C", "A9", "51", "A0"},
    {"7F", "0C", "F6", "6F", "17", "C4", "49", "EC", "D8", "43", "1F", "2D", "A4", "76", "7B", "B7"},
    {"CC", "BB", "3E", "5A", "FB", "60", "B1", "86", "3B", "52", "A1", "6C", "AA", "55", "29", "9D"},
    {"97", "B2", "87", "90", "61", "BE", "DC", "FC", "BC", "95", "CF", "CD", "37", "3F", "5B", "D1"},
    {"53", "39", "84", "3C", "41", "A2", "6D", "47", "14", "2A", "9E", "5D", "56", "F2", "D3", "AB"},
    {"44", "11", "92", "D9", "23", "20", "2E", "89", "B4", "7C", "B8", "26", "77", "99", "E3", "A5"},
    {"67", "4A", "ED", "DE", "C5", "31", "FE", "18", "0D", "63", "8C", "80", "C0", "F7", "70", "07"}};



// Hex To Int
unordered_map<char, int> dict; 

int hex_to_int(char a){
    if(a >= '0' && a <= '9') return (a - 48);
    else if(a >= 'A' && a <= 'Z') return(a - 55);
    return(a - 87);
}

// XOR Hex Strings
string xor_strings(string str1, string str2){
    stringstream xored_string;
    itr(i, str2.length()) {
        xored_string << hex << (hex_to_int(str1[i]) ^ hex_to_int(str2[i]));
    }
    return xored_string.str();
}

string leftShitOneCircular(string s) {
      char temp = s[0];
      for(int i = 0; i < s.length() - 1; ++i) s[i] = s[i + 1];
      s[s.length() - 1] = temp;
      return s;
}

string g_function(string s, int rno) {
    string LCS = leftShitOneCircular(leftShitOneCircular(s));
    string subs = "";
    
     
    for(int i = 0; i < LCS.length(); i += 2) {
        subs += S_Box[dict[LCS[i]]][dict[LCS[i + 1]]];
    }
    return xor_strings(subs, Rcon[rno]);
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

string add_hex_strings(string hex1, string hex2)
{
    if (hex1.length() < hex2.length())
        hex1.swap(hex2);
    int length1, length2;
    length1 = hex1.length();
    length2 = hex2.length();
    int get1, get2;
    int sum;
    int flag = 0;
    while (length1>0)
    {
        if (hex1[length1 - 1] >= 'A')
            get1 = hex1[length1 - 1] - 55;
        else
            get1 = hex1[length1 - 1] - '0';

        if (length2 > 0)
        {
            if (hex2[length2 - 1] >= 'A')
                get2 = hex2[length2 - 1] - 55;
            else
                get2 = hex2[length2 - 1] - '0';
        }
        else
            get2 = 0;

        //get the sum
        sum = get1 + get2 + flag;

        if (sum >= 16)
        {
            int left = sum % 16;
            if (left >= 10)
                hex1[length1 - 1] = 'A' + left % 10;
            else
                hex1[length1 - 1] = '0' + left;
            flag = 1;
        }
        else
        {
            if (sum >= 10)
                hex1[length1 - 1] = 'A' + sum % 10;
            else
                hex1[length1 - 1] = '0' + sum;
            flag = 0;
        }

        length1--;
        length2--;
    }

    if (flag == 1)
        return "1" + hex1;
    else
        return hex1;
}


string division(string a, string b) {
    /*
    a*b = 
    if(a == 01) then return b
    temp = L(a) + L(b)
    if temp.length() > 2 then temp = temp - FF (temp + 01)
    return E(temp)
    */
   if(a == "01") return b;
   if(b == "00") return b;

    string temp = add_hex_strings(
        L_Table[dict[a[0]]][dict[a[1]]],
        L_Table[dict[b[0]]][dict[b[1]]]
    );

    if(temp.length() > 2) {
        temp = add_hex_strings(
            temp, "01"
        );
        temp = temp.substr(1);
    }

    return E_Table[dict[temp[0]]][dict[temp[1]]];
}


string get_string(char x) {
    string str(1, x);
    return str;    
}

void check(string third) {
    vector<string> w(16);
    string StateMatrix[4][4];
    for(int i = 0; i < third.length(); i += 2) {
        w[i / 2] = get_string(third[i]) + get_string(third[i + 1]);
    }
    StateMatrix[0][0] = w[0];
    StateMatrix[1][0] = w[1];
    StateMatrix[2][0] = w[2];
    StateMatrix[3][0] = w[3];
    StateMatrix[0][1] = w[4];
    StateMatrix[1][1] = w[5];
    StateMatrix[2][1] = w[6];
    StateMatrix[3][1] = w[7];
    StateMatrix[0][2] = w[8];
    StateMatrix[1][2] = w[9];
    StateMatrix[2][2] = w[10];
    StateMatrix[3][2] = w[11];
    StateMatrix[0][3] = w[12];
    StateMatrix[1][3] = w[13];
    StateMatrix[2][3] = w[14];
    StateMatrix[3][3] = w[15];

    itr(i, 4) {
            itr(j, 4) cout << StateMatrix[i][j] << " ";
            nl;
        }
}

void solution() {
    //
    string plain_text, key_word; cin >> plain_text >> key_word;
    // Generate round keys
    vector<string> keys(11);
    keys[0] = key_word;
    itr(i, 10) {
        string key = keys[i];
        string w0 = key.substr(0, 8);
        string w1 = key.substr(8, 8);
        string w2 = key.substr(16, 8);
        string w3 = key.substr(24, 8);
        string w4 = xor_strings(w0, g_function(w3, i));
        string w5 = xor_strings(w1, w4);
        string w6 = xor_strings(w2, w5);
        string w7 = xor_strings(w3, w6);
        string temp = w4 + w5 + w6 + w7;
        transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
        keys[i + 1] = temp;
    }
    itr1(i, 1, 11) cout << keys[i] << endl;

    // Compute cipher text

    // 1. Xor round key with state matrix
    string first = xor_strings(plain_text, keys[0]);
    transform(first.begin(), first.end(), first.begin(), ::toupper);
    // check(first);
    for(int x = 1; x <= 10; ++x) {
        /////////////////////////////

        // 2. Byte Substitution
        string second = "";
        for(int i = 0; i < first.length(); i += 2) {
            second += S_Box[dict[first[i]]][dict[first[i + 1]]];
        }
        transform(second.begin(), second.end(), second.begin(), ::toupper);
        // cout << "Byte Subst" << endl;
        // check(second);
        // 3. Shift Rows
        vector<string> w(16);
        for(int i = 0; i < second.length(); i += 2) {
            w[i / 2] = get_string(second[i]) + get_string(second[i + 1]);
        }
        string third = "";
        third = w[0] + w[5] + w[10] + w[15]
                + w[4] + w[9] + w[14] + w[3]
                + w[8] + w[13] + w[2] + w[7]
                + w[12] + w[1] + w[6] + w[11];
        
        transform(third.begin(), third.end(), third.begin(), ::toupper);
        // cout << "Shift Row" << endl;
        // check(third);
        // Last round is partial round
        if(x == 10) {
            plain_text = third;
            break;
        }
        
        // 4. Mix Column
        string MixColMatrix[4][4] = {
            {"02", "03", "01", "01"},
            {"01", "02", "03", "01"},
            {"01", "01", "02", "03"},
            {"03", "01", "01", "02"}
        };
        string StateMatrix[4][4];
        for(int i = 0; i < third.length(); i += 2) {
            w[i / 2] = get_string(third[i]) + get_string(third[i + 1]);
        }
        StateMatrix[0][0] = w[0];
        StateMatrix[1][0] = w[1];
        StateMatrix[2][0] = w[2];
        StateMatrix[3][0] = w[3];
        StateMatrix[0][1] = w[4];
        StateMatrix[1][1] = w[5];
        StateMatrix[2][1] = w[6];
        StateMatrix[3][1] = w[7];
        StateMatrix[0][2] = w[8];
        StateMatrix[1][2] = w[9];
        StateMatrix[2][2] = w[10];
        StateMatrix[3][2] = w[11];
        StateMatrix[0][3] = w[12];
        StateMatrix[1][3] = w[13];
        StateMatrix[2][3] = w[14];
        StateMatrix[3][3] = w[15];

        string res[4][4];
        itr(i, 4) {itr(j, 4) { 
            string temp = "00";
            for(int k = 0; k < 4; k++) {
                string a = MixColMatrix[i][k];
                string b = StateMatrix[k][j];
                string temp1 = division(a, b);
                transform(temp1.begin(), temp1.end(), temp1.begin(), ::toupper);
                temp = xor_strings(temp, temp1);
                transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
            }
            res[i][j] = temp; 
        }
        } 

        // itr(i, 4) {
        //     itr(j, 4) cout << res[i][j] << " ";
        //     nl;
        // }

        // 1. Xor round key with state matrix
        
        plain_text = "";
        itr(j, 4) itr(i, 4) plain_text += res[i][j];
        transform(plain_text.begin(), plain_text.end(), plain_text.begin(), ::toupper);
        // cout << "Mix Col" << endl;
        // check(plain_text);
        first = xor_strings(plain_text, keys[x]);
        transform(first.begin(), first.end(), first.begin(), ::toupper);
        // cout << "Add Round Key" << endl;
        // check(first);
    }
    string t = xor_strings(plain_text, keys[10]);
    transform(t.begin(), t.end(), t.begin(), ::toupper);
    cout << t << endl;
}

int32_t main() {
    IOS;
    dict['0'] = 0; 
    dict['1'] = 1;
    dict['2'] = 2;
    dict['3'] = 3;
    dict['4'] = 4; 
    dict['5'] = 5;
    dict['6'] = 6;
    dict['7'] = 7; 
    dict['8'] = 8; 
    dict['9'] = 9; 
    dict['A'] = 10; 
    dict['B'] = 11; 
    dict['C'] = 12; 
    dict['D'] = 13; 
    dict['E'] = 14; 
    dict['F'] = 15;
    solution();
    return 0;
}