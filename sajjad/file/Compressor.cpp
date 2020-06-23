#include "Compressor.h"
#include <iostream>
#include <unordered_map>
#include <bits/stdc++.h>

using namespace std;

vector<int> Compressor::putFileToVec(const string &aa) {
    vector<int> b;

    ifstream myfile(aa);
    if (!myfile.is_open()) {
        return b; //unable to open file
    }
    unsigned char q0, q1, q2, q3;
    myfile >> noskipws;
    while (myfile >> q0) {
        myfile >> q1;
        myfile >> q2;
        myfile >> q3;
        int num = (int) (q0 << 24 | q1 << 16 | q2 << 8 | q3);
        b.push_back(num);
    }
    return b;
}

vector<unsigned char> Compressor::intToBytes(int paramInt) {
    vector<unsigned char> arrayOfByte(4);
    for (int i = 0; i < 4; i++)
        arrayOfByte[3 - i] = (paramInt >> (i * 8));
    return arrayOfByte;
}

void Compressor::putVecToFile(const string &path, const vector<int> &output_code) {
    ofstream myFileForOut;
    myFileForOut.open(path);
    for (int i = 0; i < output_code.size(); i++) {
        vector<unsigned char> byteArr = intToBytes(output_code[i]);
        myFileForOut << byteArr[0];
        myFileForOut << byteArr[1];
        myFileForOut << byteArr[2];
        myFileForOut << byteArr[3];
    }
    myFileForOut.close();
}

Compressor::Compressor(std::string &input, std::string &output) {
    m_input = input;
    m_output = output;
}

bool Compressor::compress() noexcept {
    unordered_map<string, int> table;
    for (int i = 0; i <= 255; i++) {
        string ch = "";
        ch += char(i);
        table[ch] = i;
    }

    string s1 = "";
    unsigned char nextChar;
    ifstream myFile(m_input);
    myFile >> std::noskipws;
    if (!myFile.is_open()) {
        return false; // Unable to open file
    }
    while (myFile >> nextChar)
        s1 += nextChar;
    myFile.close();
    string p = "", c = "";
    p += s1[0];
    int code = 256;
    vector<int> output_code;

    for (int i = 0; i < s1.length(); i++) {
        if (i != s1.length() - 1)
            c += s1[i + 1];
        if (table.find(p + c) != table.end()) {
            p = p + c;
        } else {
            output_code.push_back(table[p]);
            table[p + c] = code;
            code++;
            p = c;
        }
        c = "";
    }
    output_code.push_back(table[p]);

    putVecToFile(m_output, output_code);

    return true;
}

bool Compressor::decompress() noexcept {
    vector<int> op = putFileToVec(m_input);

    ofstream myFileForOutput;
    myFileForOutput.open(m_output);

    unordered_map<int, string> table;
    for (int i = 0; i <= 255; i++) {
        string ch = "";
        ch += char(i);
        table[i] = ch;
    }
    int old = op[0], n;
    string s = table[old];
    string c = "";
    c += s[0];
    myFileForOutput << s;

    int count = 256;
    for (int i = 0; i < op.size() - 1; i++) {
        n = op[i + 1];
        if (table.find(n) == table.end()) {
            s = table[old];
            s = s + c;
        } else {
            s = table[n];
        }
        myFileForOutput << s;
        c = "";
        c += s[0];
        table[count] = table[old] + c;
        count++;
        old = n;
    }
    myFileForOutput.close();
    return true;
}