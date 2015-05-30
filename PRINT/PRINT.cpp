#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cmath>
#include <memory.h>

#include <vector>
#include <algorithm>

using namespace std;

typedef vector<unsigned int> Integers;

char outBuffer[1000000];
size_t posBuffer;

void Flush() {
    fwrite(outBuffer, posBuffer, 1, stdout);
    posBuffer = 0;
}

static char outBuf[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '\n' };
static char* END = outBuf + sizeof(outBuf) - 2;

void Out(register int num) {
    register char* end = END;

    while (num) {
        *end = (num % 10) + '0';
        --end;
        num /= 10;
    }

    int len = END - end + 1;
    memcpy(outBuffer + posBuffer, end + 1, len);
    posBuffer += len;
}

int main() {
    // freopen("input.txt", "r", stdin);

    static const int MAXN = 46500;
    Integers primes;
    vector<bool> sieve(MAXN, true);
    for (int i = 2; i < MAXN; ++i) {
        if (sieve[i]) {
            primes.push_back(i);
            int j = i + i;
            while (j < MAXN) {
                sieve[j] = false;
                j += i;
            }
        }
    }

    posBuffer = 0;

    int nT;
    scanf("%d", &nT);
    vector<bool> erato(1000000 + 1);
    for (int iTest = 0; iTest < nT; ++iTest) {
        unsigned int l;
        unsigned int r;
        scanf("%u%u", &l, &r);
        if (1 == l) {
            ++l;
        }

        int top = 0;
        int bound = static_cast<int>(sqrt(r) + 0.0001);
        while (primes[top] <= bound) {
            ++top;
        }

        int n = r - l + 1;
        fill(erato.begin(), erato.begin() + n, true);

        for (int iPrime = 0; iPrime < top; ++iPrime) {
            const int p = primes[iPrime];
            register int begin = l % p;
            if (begin) {
                begin = p - begin;
            }
            if (p <= r && p >= l) {
                begin += p;
            }
            while (begin < n) {
                erato[begin] = false;
                begin += p;
            }
        }

        for (int i = 0; i < n; ++i) {
            if (erato[i]) {
                Out(l + i);
            }
        }

        Flush();
    }

    return 0;
}