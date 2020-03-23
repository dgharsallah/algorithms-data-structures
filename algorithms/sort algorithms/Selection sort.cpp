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
 
int n, pref[N], suf[N];
string s;

vector<int> selectionSort(const vector<int> &arr) {
    vector<int> v = arr;
    int idx, mn;
    for (int i = 0; i < v.size(); ++i) {
        idx = i, mn = 1e9;
        for (int j = i; j < v.size(); ++j) {
            if (v[j] < mn) {
                mn = v[j];
                idx = j;
            }
        }
        swap(v[i], v[idx]);
    }
    return v;
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
        if (selectionSort(tc.input) != tc.output) {
            cout << "Testcase failed\n";
            return 0;
        }
    }
    cout << "Passed the testcases!\n";
    return 0;
}
