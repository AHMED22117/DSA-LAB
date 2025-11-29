#include <iostream>
#include <cstring>
using namespace std;

void buildLPS(const char pat[], int m, int lps[]) {
    int len = 0;
    lps[0] = 0;

    int i = 1;
    while (i < m) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0)
                len = lps[len - 1];
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMP(const char text[], const char pat[]) {
    int n = strlen(text);
    int m = strlen(pat);

    int lps[1000];
    buildLPS(pat, m, lps);

    cout << "LPS Array: ";
    for (int i = 0; i < m; i++) cout << lps[i] << " ";
    cout << endl;

    int i = 0, j = 0;
    while (i < n) {
        if (text[i] == pat[j]) {
            i++;
            j++;
        }
        if (j == m) {
            cout << i - j << " ";
            j = lps[j - 1];
        }
        else if (i < n && text[i] != pat[j]) {
            if (j != 0) j = lps[j - 1];
            else i++;
        }
    }
}

int main() {
    const char text[] = "abababababc";
    const char pat[] = "abab";
    KMP(text, pat);
    return 0;
}
