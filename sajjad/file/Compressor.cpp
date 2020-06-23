#include "Compressor.h"
#include <iostream>
#include <unordered_map>
#include <bits/stdc++.h>

using namespace std;

vector<int> Compressor::put_file_to_vector(const string &file_path) {
    vector<int> result;

    ifstream myfile(file_path);
    if (!myfile.is_open()) {
        return result; //unable to open file
    }
    unsigned char c0, c1, c2, c3;
    myfile >> noskipws;
    while (myfile >> c0) {
        myfile >> c1;
        myfile >> c2;
        myfile >> c3;
        int num = (int) (c0 << 24 | c1 << 16 | c2 << 8 | c3);
        result.push_back(num);
    }
    return result;
}

vector<unsigned char> Compressor::int_to_bytes(int paramInt) {
    int size_of_int = sizeof(int);
    vector<unsigned char> arrayOfByte(size_of_int);
    for (int i = 0; i < size_of_int; i++)
        arrayOfByte[size_of_int - 1 - i] = (paramInt >> (i * 8));
    return arrayOfByte;
}

void Compressor::put_vector_to_file(const string &path, const vector<int> &output_code) {
    ofstream myFileForOut;
    myFileForOut.open(path);
    for (int i = 0; i < output_code.size(); i++) {
        vector<unsigned char> byteArr = int_to_bytes(output_code[i]);
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

    string input_str = "";
    unsigned char nextChar;
    ifstream myFile(m_input);
    myFile >> std::noskipws;
    if (!myFile.is_open()) {
        return false; // Unable to open file
    }
    while (myFile >> nextChar)
        input_str += nextChar;
    myFile.close();
    string repeated_str = "", next_str = "";
    repeated_str += input_str[0];
    int code = 256;
    vector<int> output_code;

    for (int i = 0; i < input_str.length(); i++) {
        if (i != input_str.length() - 1)
            next_str += input_str[i + 1];
        if (table.find(repeated_str + next_str) != table.end()) {
            repeated_str = repeated_str + next_str;
        } else {
            output_code.push_back(table[repeated_str]);
            table[repeated_str + next_str] = code;
            code++;
            repeated_str = next_str;
        }
        next_str = "";
    }
    output_code.push_back(table[repeated_str]);

    put_vector_to_file(m_output, output_code);

    return true;
}

bool Compressor::decompress() noexcept {
    vector<int> output_vector = put_file_to_vector(m_input);

    ofstream myFileForOutput;
    myFileForOutput.open(m_output);

    unordered_map<int, string> table;
    for (int i = 0; i <= 255; i++) {
        string ch = "";
        ch += char(i);
        table[i] = ch;
    }
    int old = output_vector[0], n;
    string repeated_str = table[old];
    string next_str = "";
    next_str += repeated_str[0];
    myFileForOutput << repeated_str;

    int count = 256;
    for (int i = 0; i < output_vector.size() - 1; i++) {

        n = output_vector[i + 1];
        if (table.find(n) == table.end()) {
            repeated_str = table[old];
            repeated_str = repeated_str + next_str;
        } else {
            repeated_str = table[n];
        }
        myFileForOutput << repeated_str;
        next_str = "";
        next_str += repeated_str[0];
        table[count] = table[old] + next_str;
        count++;
        old = n;
    }
    myFileForOutput.close();
    return true;
}