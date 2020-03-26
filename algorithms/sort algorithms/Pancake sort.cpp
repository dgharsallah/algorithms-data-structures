#include <iostream>
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#define ll long long
using namespace std;

const int N = 1e6 + 7;

void flip(vector<int>& a, int k) {
  reverse(a.begin(), a.begin() + k);
}

vector<int> pancakeSort(vector<int>& a) {
  if (a.empty()) return {};
  int n = a.size();
  // this loop to look for the ith max
  for (int i = 0; i < n; ++i) {
    int mx = a[0], idxMax = 0;
    // j iterates over the non sorted part of the array
    for (int j = 0; j < n - i; ++j) {
      if (a[j] > mx) {
        mx = a[j];
        idxMax = j;
      }
    }
    flip(a, idxMax + 1);
    // now I have my ith max at the top of the array
    flip(a, n - i);
  }
  return a;
}

struct testcase {
    vector<int> input, output;
};

int main() {
    vector<testcase> testcases = {testcase{
        input: {2, -1, 12, 52, 9, 13},
        output:{-1, 2, 9, 12, 13, 52}
    },
        testcase{input:{}, output:{}},
        testcase{input:{1}, output:{1}},
        testcase{input:{3, 2, 1}, output:{1, 2, 3}}
    };
    for (auto tc : testcases) {
        if (pancakeSort(tc.input) != tc.output) {
            cout << "Testcase failed\n";
            return 0;
        }
    }
    cout << "Passed the testcases!\n";
    return 0;
}
