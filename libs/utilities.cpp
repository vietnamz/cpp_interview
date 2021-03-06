#include "utilities.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <sstream>

using namespace std;

#include <iterator>
#include <boost/filesystem.hpp>
#include <boost/filesystem/fstream.hpp>


namespace fs = boost::filesystem;


int count_to_10() {
    fs::path fpath {"count.txt"};
    fs::ofstream ofs {fpath};
    for(auto &ndx : {1,2,3,4,5,6,7,8,9,10}) {
        ofs << "Line $" << ndx << '\n';
    }
	return 0;
}

int test_enum() {
	TrafficLight color = TrafficLight::red;
	CarColor camry = CarColor::silver;
	int colorNumber  = red;
	int myCarsColor = black;
	Pet apet = Pet::bird;
	Mammal m = Mammal::dog;
	return 0;
}
const string& getHelloWorld() {
	return HELLO_WORLD;
}

string test_variadic_template() {
	string s1 = "foo", s2 = "zoo", s3 = "noo";
	string cc = rcatenate(s1, s2, s3);
	return cc;
}

int add_sum_template() {
	int a = 4, b = 6, c = 8, d = 9;
	int result = summer(a,b,c,d);
	return result;
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

void segregate_character(vector<char>& listOfChar) {
	int R_count = 0;
	int G_count = 0;
	int B_count = 0;
	for(char c : listOfChar) {
		if ( c == 'R' ) {
			R_count++;
		} else if( c == 'G' ) {
			G_count++;
		} else if ( c == 'B' ) {
			B_count++;
		} else {
			throw std::invalid_argument("Invalid");
		}
	}
	for(int i = 0; i < listOfChar.size(); i++) {
		if ( i < R_count ) {
			listOfChar[i] = 'R';
		} else if ( i >= R_count && i < (R_count + G_count)) {
			listOfChar[i] = 'G';
		} else {
			listOfChar[i] = 'B';
		}
	}
}

vector<string> break_string(const string& input) {
	vector<string> output;
	stringstream ss(input);
	string str;
	while(getline(ss, str, '"')) {
		output.push_back(str);
	}
	vector<string> new_out;
	std::remove_copy_if(output.begin(), output.end(), std::back_inserter(new_out), [](string a) { return a == "" or a == "," ; } );
	return new_out;
}

bool isPalindrome(string word)
{
  // Please write your code here.
  map<char,int> aMap;
  for (char c : word) {
    auto tmp = aMap.find(c);
    if (tmp != aMap.end()) {
      aMap[tolower(c)]++;
    } else {
      aMap[tolower(c)] = 1;
    }
  }
  int count = 0;
  for(auto t : aMap) {
    if( (t.second % 2) == 1 ) {
      count++;
    }
  }
  if ( count >= 2 ) {
    return false;
  }
  return true;
}

int find_non_duplicate(const vector<int>& vec) {
	int count = std::accumulate(vec.begin(), vec.end(),0);
	int idx_start = 0;
	int idx_end = vec.size() ;
	while(idx_start < idx_end ) {
		if (vec[idx_start] != vec[idx_end]) {
			if ( vec[idx_start] != vec[idx_end - 1]) {
				idx_end--;
			} else {
				if ( idx_start == idx_end -1 ) {
					break;
				}
				idx_start++;
			}
		} else {
			idx_start++;
			idx_end--;
		}
	}

	return vec[idx_start];
}

int binarian(vector<int>& input) {
	int len = input.size();
	int result = 0;
	for ( int data : input) {
		result += pow(2, data);
	}
	return result;
}

int count_set_bits(int num) {
	int count = 0;
	while( num > 0 ) {
		num &= (num-1);
		count += 1;
	}
	return count;
}
int binarian_t(vector<int>& input) {
	int b = binarian(input);
	return count_set_bits(b);
}

int third_biggest_number(const vector<int>& alist) {
	int biggest_num = INT_MIN;
	for(int i : alist) {
		if ( i > biggest_num ) {
			biggest_num = i;
		}
	}
	int second_biggest_num = INT_MIN;
	for(int i : alist) {
		if ( i > second_biggest_num && i < biggest_num ) {
			second_biggest_num = i;
		}
	}
	int third_biggest_num = INT_MIN;
	for(int i: alist ) {
		if (i > third_biggest_num && i < second_biggest_num ) {
			third_biggest_num = i;
		}
	}
	return third_biggest_num;
}

int profit_sort(vector<int>& profit, int l, int r) {
  /*
  int myints[] = {10,20,30,30,20,10,10,20};
  std::vector<int> v(myints,myints+8);           // 10 20 30 30 20 10 10 20

  std::sort (v.begin(), v.end());                // 10 10 10 20 20 20 30 30 */
// 23,13,10,2,33, 2, 10, 13, 23, 33
  vector<int>::iterator low,up;
  up = lower_bound (profit.begin(), profit.end(), r); //     
  if ( find(profit.begin(), profit.end(), r) != profit.end() )
  {
	  up = up + 1;
  }   
  low =  upper_bound (profit.begin(), profit.end(), l); // 
  if ( find(profit.begin(), profit.end(), l) != profit.end() )
  {
	  low = low  - 1;
  }        
  return (up - low);
}