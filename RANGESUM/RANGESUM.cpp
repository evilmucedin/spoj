#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct TListItem {
	int _number;
	long long int _sum;
	bool _calced;
};

typedef vector<TListItem> TListItems;
typedef vector<int> Integers;

static const int M = 1000;

void Insert(TListItems& list, int number) {
	TListItem item;
	item._number = number;
	item._calced = false;
	list.push_back(item);
	if (0 == (list.size() % M)) {
		int begin = static_cast<int>(list.size()) - M;
		if (begin >= 0) {
			long long int sum = 0;
			for (int i = 0; i < M; ++i) {
				sum += list[i + begin]._number;
			}
			list[begin]._sum = sum;
			list[begin]._calced = true;
		}
	}
}

long long int Sum(const TListItems& list, int begin, int end) {
	long long int result = 0;
	while (begin <= end) {
		if ((0 == (begin % M)) && (begin + M < end) && (list[begin]._calced)) {
			result += list[begin]._sum;
			begin += M;
		} else {
			result += list[begin]._number;
			++begin;
		}
	}
	return result;
}

int main() {
	// ifstream fIn("input.txt");
	// cin.rdbuf(fIn.rdbuf());
	
	int n;
	cin >> n;

	Integers inp(n);
	for (int i = 0; i < n; ++i) {
		cin >> inp[i];
	}

	TListItems items;
	
	for (Integers::const_reverse_iterator toN = inp.rbegin(); toN != inp.rend(); ++toN) {
		Insert(items, *toN);
	}

	int m;
	cin >> m;
	for (int i = 0; i < m; ++i) {
		int command;
		cin >> command;
		if (1 == command) {
			int begin;
			int end;
			cin >> begin >> end;
			begin = items.size() - begin;
			end = items.size() - end;
			swap(begin, end);
			cout << Sum(items, begin, end) << endl;
		} else {
			int num;
			cin >> num;
			Insert(items, num);
		}
	}

	return 0;
}