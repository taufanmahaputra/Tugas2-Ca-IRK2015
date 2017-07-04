#include <iostream>
#include <vector>
#include <string>

#define phb push_back
#define pob pop_back
using namespace std;

void wordToNumber(string word, vector<int>& number);
string numberToWord(const vector<int> number);

int main() {
	vector<int> number;
	string word; //menyimpan input kalimat
	getline(cin,word);
	cout << word << endl;
	
	// Konversi kata ke deretan ASCII number
	wordToNumber(word,number);

	for(int i = 0; i < number.size(); i++)
		cout << number[i];
	return 0;
}

void wordToNumber(string word, vector<int>& number) {
	for(int i = 0; i < word.length(); i++) {
		number.phb(int(word[i]));
	}
}

string numberToWord(const vector<int> number) {

}