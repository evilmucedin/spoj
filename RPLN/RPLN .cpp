#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cmath>

#include <vector>
#include <limits>

using namespace std;

typedef vector<int> Integers;

template<typename T>
T Min(T a, T b) {
	return (a < b) ? a : b;
}

int main() {
	// freopen("input.txt", "r", stdin);

	int nTest;
	scanf("%d", &nTest);
	Integers nums;
	static const int INF = numeric_limits<int>::max();
	for (int iTest = 0; iTest < nTest; ++iTest) {
		int n;
		int q;
		scanf("%d%d", &n, &q);
		nums.resize(n);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &nums[i]);
		}
		n = 1 << static_cast<int>((log(n - 1) / log(2) + 1));
		nums.resize(2 * n, INF);
		for (int i = 0; i < n; ++i) {
			nums[n + i] = nums[i];
		}
		for (int i = n - 1; i >= 0; --i) {
			nums[i] = Min(nums[2 * i], nums[2 * i + 1]);
		}
		printf("Scenario #%d:\n", iTest + 1);
		for (int i = 0; i < q; ++i) {
			int res = INF;
			int a;
			int b;
			scanf("%d%d", &a, &b);
			a += n - 1;
			b += n - 1;
			while (a <= b) {
				if (a & 1) {
					res = Min(res, nums[a]);
				}
				if (!(b & 1)) {
					res = Min(res, nums[b]);
				}
				a = (a + 1) / 2;
				b = (b - 1) / 2;
			}
			printf("%d\n", res);
		}
	}

	return 0;
}