#define PATH "myFile.txt"
#define OLSPATH	"oneLetterSentence.txt"
#define MLSPATH	"multipleLetterSentence.txt"


#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	string line;
	fstream file;
	fstream oneLetterSentence;
	fstream multLetSent;	//multipleLetterSentence


	file.exceptions(ifstream::badbit);
	try {
		file.open(PATH);
	}
	catch (const ifstream::failure& ex) {
		cout << "Error occured while opening the file." << endl;
		cout << ex.what() << endl << ex.code() << endl;
	}

	oneLetterSentence.exceptions(ifstream::badbit);
	try {
		oneLetterSentence.open(OLSPATH);
	}
	catch (const ifstream::failure& ex) {
		cout << "Error occured while opening the file." << endl;
		cout << ex.what() << endl << ex.code() << endl;
	}

	multLetSent.exceptions(ifstream::badbit);
	try {
		multLetSent.open(MLSPATH);
	}
	catch (const ifstream::failure& ex) {
		cout << "Error occured while opening the file." << endl;
		cout << ex.what() << endl << ex.code() << endl;
	}

	while (!file.eof()) {
		getline(file, line);
		if ((line.length() == 1) && (line[0] != ' ')) {
			oneLetterSentence << line << endl;
		}
		else if ((line.length() > 2) && (line[0] != ' ') && (line[1] == ' ' || line[1] == '.' || line[1] == ',' || line[1] == '-')) {
			oneLetterSentence << line << endl;
		}
		else
			multLetSent << line << endl;
	}

	oneLetterSentence.clear();
	oneLetterSentence.seekg(0);
	while (!oneLetterSentence.eof()) {
		getline(oneLetterSentence, line);
		cout << line << endl;
	}

	multLetSent.clear();
	multLetSent.seekg(0);
	while (!multLetSent.eof()) {
		getline(multLetSent, line);
		cout << line << endl;
	}
	file.close();
	oneLetterSentence.close();
	multLetSent.close();
	return 0;
}