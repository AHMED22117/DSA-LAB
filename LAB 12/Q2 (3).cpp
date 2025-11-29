#include <iostream>
#include <cstring>
using namespace std;

#define PRIME 101

long long createHash(const char str[], int m) {
    long long h = 0;
    for (int i = 0; i < m; i++)
        h = (h * 256 + str[i]) % PRIME;
    return h;
}

long long recalcHash(long long oldHash, char oldChar, char newChar, int power) {
    long long h = (oldHash - oldChar * power) % PRIME;
    if (h < 0) h += PRIME;
    h = (h * 256 + newChar) % PRIME;
    return h;
}

void rabinKarp(const char text[], const char pat[]) {
    int n = strlen(text);
    int m = strlen(pat);

    long long patHash = createHash(pat, m);
    long long txtHash = createHash(text, m);

    long long power = 1;
    for (int i = 1; i <= m - 1; i++)
        power = (power * 256) % PRIME;

    for (int i = 0; i <= n - m; i++) {
        if (patHash == txtHash) {
            bool match = true;

            for (int j = 0; j < m; j++) {
                if (text[i + j] != pat[j]) {
                    match = false;
                    cout << "False positive at index " << i << endl;
                    break;
                }
            }
            if (match) cout << i << " ";
        }

        if (i < n - m)
            txtHash = recalcHash(txtHash, text[i], text[i + m], power);
    }
}

int main() {
    const char text[] = "Data structures and algorithms are fun. Algorithms make tasks easier.";
    const char pattern[] = "Algorithms";

    rabinKarp(text, pattern);
    return 0;
}
