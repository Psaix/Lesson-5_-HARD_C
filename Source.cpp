#include <iostream>
#include <list>
#include <map>
#include <algorithm>
#include <vector>
#include <sstream>
#include <set>
#include <deque>
#include <unordered_set>

using namespace std;

// task1

template<class T>
void __fastcall printUnique(T itBegin, T itEnd) {
	set<string> uniques;

	copy(itBegin, itEnd, inserter(uniques, uniques.begin()));

	for (auto it : uniques) {
		cout << it << " ";
	}

	cout << endl << endl;
}


int main() {

	//task1

	list<string> list1 = { "One", "Two", "Three", "Four", "Five", "Six", "Seven", "One", "Two", "Three", "One", "Two" };
	vector<string> vector1 = { "One", "Two", "Three", "Four", "Five", "Six", "Seven", "One", "Two", "Three", "One", "Two" };
	set<string> set1 = { "One", "Two", "Three", "Four", "Five", "Six", "Seven", "One", "Two", "Three", "One", "Two" };
	multiset<string> multiset1 = { "One", "Two", "Three", "Four", "Five", "Six", "Seven", "One", "Two", "Three", "One", "Two" };
	deque<string> deque1 = { "One", "Two", "Three", "Four", "Five", "Six", "Seven", "One", "Two", "Three", "One", "Two" };

	printUnique(list1.begin(), list1.end());
	printUnique(vector1.begin(), vector1.end());
	printUnique(set1.begin(), set1.end());
	printUnique(multiset1.begin(), multiset1.end());
	printUnique(deque1.begin(), deque1.end());

	//task2
	struct vCompare {
		bool __fastcall operator()(const vector<string>& v1, const vector<string>& v2) const {
			return v1.size() < v2.size();
		};
	};


	multiset<vector<string>, vCompare> text;

	vector<string> curSentence;

	string sInput;
	size_t iSentenceIndex = 0;

	while (true) {
		sInput.clear();

		cin.clear();
		cin.ignore(86400, '\n');

		cout << "Enter your sentence, or 'STOP' to break: " << endl;
		getline(cin, sInput);

		if (sInput == "STOP" || sInput.length() == 0) break;

		size_t iCur = 0;
		size_t iNext = 0;

		size_t iStrLastIndex = sInput.length() - 1;

		do {
			iNext = sInput.find(" ", iCur);

			if (iNext == string::npos) {
				iNext = iStrLastIndex;
			}

			curSentence.push_back(sInput.substr(iCur, iNext - iCur + 1));

			iCur = iNext + 1;

		} while (iNext < iStrLastIndex);


		text.insert(curSentence);
		curSentence.clear();
	}

	for (auto i : text) {
		for (auto j : i) {
			cout << j << " "; 
		}
		cout << endl;
	}

	return 0;
}