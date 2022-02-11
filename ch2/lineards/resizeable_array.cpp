#include <bits/stdc++.h>
using namespace std;

int main()
{
    // initial size (5) and initial value {7, 7, 7, 0, 0}
    int arr[5] = {7, 7, 7}, i;
    // first element indicates size
    // initial size (5) and value {4, 4, 4, 4, 4}
    vector<int> v(5, 4);

    printf("arr[2] = %d, v[2] = %d\n", arr[2], v[2]); // 7 and 4

    // stores increasing sequence starting from 0
    // 0, 1, 2, 3, 4
    iota(arr, arr+5, 0);
    // 7, 8, 9, 10, 11
    iota(v.begin(), v.end(), 7);
    printf("arr[2] = %d, v[2] = %d\n", arr[2], v[2]); // 2 and 9

    // undefined behavior
    // arr[5] = 5;
    // RTE
    // printf("arr[5] = %d\n", arr[5]);  (?? didn't give error in codeblocks 20.03)

    // vector resizes itself
    v.push_back(77);
    printf("v[5] = %d\n", v[5]); // 77

    return 0;
}
