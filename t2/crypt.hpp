#ifndef CRYPT_HPP
#define CRYPT_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <locale>
#include <algorithm>

using namespace std;

string LoadMessage(string filename);

bool WriteMessage(string tip, string message);

bool EncryptMessage(string operatorName);

bool Compare(pair<string, size_t> i, pair<string, size_t> j);

string DecryptMessage(string filename, string operatorName);

string getTip(string filename);

vector<pair<unsigned char, string>> EncodingTableMaker(stringstream &sst);

#endif