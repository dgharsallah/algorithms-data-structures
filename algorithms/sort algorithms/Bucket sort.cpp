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
#include <iomanip>
#define ll long long
using namespace std;

void bucketSort(vector<double> &arr) {
    vector<double> bucket[arr.size()];
    for (int i = 0; i < arr.size(); ++i) {
        bucket[int(arr[i] * 10)].push_back(arr[i]);
    }
    for (int i = 0; i < arr.size(); ++i) {
        sort(bucket[i].begin(), bucket[i].end());
    }
    int index = 0;
    for (int i = 0; i < arr.size(); ++i) {
        for (auto e : bucket[i])
            arr[index++] = e;
    }
}

int main() {
    vector<double> arr = {0.2, 0.123, 0.85, 0.9, 0.76, 0.4, 0.32, 0.42, 0.55, 0.32};
    bucketSort(arr);
    for (auto e : arr)
        cout << e << " ";
    cout << endl;
    return 0;
}
