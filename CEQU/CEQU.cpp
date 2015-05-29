#include <iostream>

using namespace std;

int main() {
	int nT;
	cin >> nT;
	for (int iTest = 0; iTest < nT; ++iTest) {
		int a0, b0, c0;
		cin >> a0 >> b0 >> c0;
		int a = a0;
		int b = b0;
		int c = c0;
		while (0 != b) {
			int temp = a;
			a = b;
			b = temp % b;
		}
		bool solveable;
		if (0 != a) {
			solveable = c0 % a == 0;
		} else {
			if (0 != a0) {
				solveable = c0 % a0 != 0;
			} else if (0 != b0) {
				solveable = c0 % b0 != 0;
			} else {
				solveable = c0 == 0;
			}
		}
		cout << "Case " << iTest + 1 << ": " << (solveable ? "Yes" : "No") << endl;
	}
	return 0;
}