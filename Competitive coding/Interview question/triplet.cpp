#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

int binarySearch(bool S[], int n, int target) {
    int left = 0;
    int right = n - 1;
    int count = 0;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (mid < target) {
            count += (S[mid] ? 1 : 0);
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return count;
}

int countTriples(bool S1[], bool S2[], bool S3[], int n, int target) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (!S1[i]) continue;
        int t = target - i;
        count += binarySearch(S2, n, t) * binarySearch(S3, n, t);
    }
    return count;
}

int main() {
    int n = 5;
    bool S1[] = {0, 1, 1, 0, 1};
    bool S2[] = {1, 0, 1, 1, 0};
    bool S3[] = {1, 1, 1, 1, 0};
    int target = 8;
    cout << "Number of triples: " << countTriples(S1, S2, S3, n, target) << endl;
    return 0;
}