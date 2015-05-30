#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

#include <vector>
#include <string>

using namespace std;

char buffer[1234567];

void IncPalindrome(const string& s, int value, string* result) {
	*result = s;
	int mid = (result->length() - 1) / 2;
	(*result)[mid] += value;
	int carry = 0;
	for (int i = result->length() - 1; i >= 0; --i) {
		int digit = (*result)[i] + carry - '0';
		(*result)[i] = (digit % 10) + '0';
		carry = digit / 10;
	}
    if (carry) {
		result->resize(s.length() + 1);
		for (int i = 0; i < result->length(); ++i) {
			(*result)[i] = '0';
		}
		(*result)[0] = '1';
		(*result)[result->length() - 1] = '1';
    } else {
        for (int i = 0; i <= mid; ++i) {
            (*result)[result->length() - i - 1] = (*result)[i];
        }
    }
}

bool IsGreather(const string& a, const string& b) {
	if (a.length() != b.length()) {
		return a.length() > b.length();
	}
	int i = 0;
	while (i < a.length() && a[i] == b[i]) {
		++i;
	}
	if (i < a.length()) {
		return a[i] > b[i];
	} else {
		return false;
	}
}

int main() {
	freopen("input.txt", "r", stdin);

	int nTest;
	scanf("%d", &nTest);
	for (int iTest = 0; iTest < nTest; ++iTest) {
		scanf("%s", buffer);
		string originalNumber(buffer);
		string candidate;
		for (int i = 0; i < 2; ++i) {
			IncPalindrome(originalNumber, i, &candidate);
			if (IsGreather(candidate, originalNumber)) {
				break;
			}
		}
		printf("%s\n", candidate.c_str());
	}
	return 0;
}