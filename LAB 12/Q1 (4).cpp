#include <iostream>
#include <cstring>
using namespace std;

void bruteForceSearch(const char text[], const char pat[]) {
    int n = strlen(text);
    int m = strlen(pat);
    int comparisons = 0;

    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        while (j < m) {
            comparisons++;
            if (text[i + j] != pat[j]) break;
            j++;
        }
        if (j == m) cout << i << " ";
    }

    cout << "\nTotal Comparisons: " << comparisons << endl;
}

int main() {
    const char text[] = "the quick brown fox jumps over the lazy dog";
    const char pattern[] = "the";

    bruteForceSearch(text, pattern);
    return 0;
}
