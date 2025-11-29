#include <iostream>
#include <cstring>
using namespace std;

void buildBadChar(const char pat[], int m, int bad[]) {
    for (int i = 0; i < 256; i++) bad[i] = -1;
    for (int i = 0; i < m; i++)
        bad[(unsigned char)pat[i]] = i;
}

void buildGoodSuffix(const char pat[], int m, int gs[]) {
    int lastPrefix = m;
    for (int i = 0; i < m; i++) gs[i] = 0;

    for (int i = m - 1; i >= 0; i--) {
        bool prefix = true;
        for (int j = 0; j < m - i - 1; j++)
            if (pat[j] != pat[i + 1 + j]) { prefix = false; break; }
        if (prefix) lastPrefix = i + 1;
        gs[i] = lastPrefix + (m - 1 - i);
    }

    for (int i = 0; i < m - 1; i++) {
        int len = 0;
        while (len <= i && pat[i - len] == pat[m - 1 - len]) len++;
        if (len == i + 1)
            gs[m - 1 - len] = m - 1 - i;
    }
}

void boyerMoore(const char text[], const char pat[]) {
    int n = strlen(text);
    int m = strlen(pat);

    int bad[256];
    int gs[1000];

    buildBadChar(pat, m, bad);
    buildGoodSuffix(pat, m, gs);

    int s = 0;
    while (s <= n - m) {
        int j = m - 1;

        while (j >= 0 && pat[j] == text[s + j])
            j--;

        if (j < 0) {
            cout << s << " ";
            s += gs[0];
        } else {
            int shiftBC = j - bad[(unsigned char)text[s + j]];
            int shiftGS = gs[j];
            s += (shiftBC > shiftGS ? shiftBC : shiftGS);
        }
    }
}

int main() {
    const char DNA[] = "ACGTACGTGACG";
    const char pattern[] = "ACG";
    boyerMoore(DNA, pattern);
    return 0;
}
