#include "Interview.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <sstream>

using namespace std;


const string& getHelloWorld() {
	return HELLO_WORLD;
}

const string kLastLines(string fileName, int k) {
	string result = "";
	ifstream myfile(fileName);
	vector<string> aVec;
	int num_line = 0;
	if (myfile.is_open()) {
		string line;
		while(getline(myfile, line)) {
			aVec.push_back(line);
			num_line++;
		}
	}
	myfile.close();
	if ( num_line < k) {
		return string("IMPOSSIBLE");
	}
	int start_idx = num_line - k;
	aVec.assign(aVec.begin()+start_idx, aVec.end());
	for(string s : aVec) {
		result += s;
	}
	return result;
}

const int countWordOccurencies(const string book, string expectedWord) {
	map<string, int> aCache;
	stringstream ss(book.c_str());
	int count = 0;
	string word;
	while(ss >> word) {
		aCache[word]++;
	}
	map<string,int>::iterator iter;
	for (iter = aCache.begin(); iter != aCache.end(); iter++) {
		if ( iter->first == expectedWord) {
			return iter->second;
		}
	}
	return 0;
}
