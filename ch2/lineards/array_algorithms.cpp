#include <bits/stdc++.h>
using namespace std;

typedef struct {
    int id;
    int solved;
    int penalty;
} team;

bool icpc_cmp(team a, team b) {
    if (a.solved != b.solved)
        return a.solved > b.solved;
    else if (a.penalty != b.penalty)
        return a.penalty < b.penalty;
    else
        return a.id < b.id;
}

int main()
{
    int arr[] = {10, 7, 2, 15, 4}, i;
    // alternative constructor
    vector<int> v(arr, arr + 5);

    cout<< "\nsort descending with vector:" << "\n";
    sort(v.rbegin(), v.rend());

    for (i = 0; i < v.size(); i++)
        cout<< v[i] << "\n";

    cout<< "\nsort descending with integer array:" << "\n";

    // ascending
    sort(arr, arr + 5);
    // then reverse
    reverse(arr, arr + 5);
    for (i = 0; i < 5; i++)
        cout<< arr[i] << "\n";

    cout<< "\nshuffle the content:" << "\n";

    random_shuffle(v.begin(), v.end());
    for (i = 0; i < v.size(); i++)
        cout<< v[i] << "\n";
    cout<< "\npartial sort demo:" << "\n";

    partial_sort(v.begin(), v.begin() + 2, v.end());
    for (i = 0; i < v.size(); i++)
        cout<< v[i] << "\n";
    cout<< "\nsort ascending:" << "\n";

    // sort ascending

    // sort array
    sort(arr, arr + 5);
    for (i = 0; i < 5; i++)
        cout<< arr[i] << "\n";
    cout<< "\n";

    // sort vector
    sort(v.begin(), v.end());
    for (i = 0; i < 5; i++)
        cout<< arr[i] << "\n";

    cout<< "\nmulti-field sorting" << "\n";
    // suppose we have 4 ICPC teams
    team nus[4] = {{1, 1, 10}, {2, 3, 60}, {3, 1, 20}, {4, 3, 60}};
    // without sorting they will be ranked like this

    for (i = 0; i < 4; i++)
        printf("id: %d, solved: %d, penalty: %d\n", nus[i].id, nus[i].solved, nus[i].penalty);
    cout<< "\n";

    sort(nus, nus+4, icpc_cmp);
    for (i = 0; i < 4; i++)
        printf("id: %d, solved: %d, penalty: %d\n", nus[i].id, nus[i].solved, nus[i].penalty);
    cout<< "\n";

    cout<< "\nanother way of multi-field sorting:" << "\n";
    // there is a way of multi-field sorting if the sorting order is "standard"
    // use pair (2 fields) or tuple (for >= 3 fields) in c++ and put the highest
    // priority infront
    typedef tuple<int, string, string> state;
    // old way
    state a = make_tuple(10, "steven", "grace");
    // c++ 17 way
    state b = {7, "steven", "halim"};
    state c = {7, "steven", "felix"};
    state d = {9, "a", "b"};

    vector<state> test;
    test.push_back(a);
    test.push_back(b);
    test.push_back(c);
    test.push_back(d);

    for (auto &[value, name1, name2] : test)
        printf("value: %d, name1: %s, name2: %s\n", value, name1.c_str(), name2.c_str());

    cout<< "\n";
    // use built-in comparator
    sort(test.begin(), test.end());
    // sorted ascending order based on value, then name1, then name2, in that order!
    for (auto &[value, name1, name2] : test)
        printf("value: %d, name1: %s, name2: %s\n", value, name1.c_str(), name2.c_str());

    cout<< "\nBinary search using lower bound:" << "\n";
    // returns address
    auto pos = lower_bound(arr, arr+5, 7); // found
    printf("%d\n", *pos);

    auto j = lower_bound(v.begin(), v.end(), 7);
    printf("%d\n", *j);

    // returns the address after last element
    pos = lower_bound(arr, arr+5, 77);
    if (pos - arr == 5)
        printf("77 not found\n");

    // returns the address after last element
    j = lower_bound(v.begin(), v.end(), 77);
    if (j == v.end())
        printf("77 not found\n");

    cout<< "\nGenerate permutation:" << "\n";
    next_permutation(arr, arr+5);
    next_permutation(arr, arr+5);

    for (i = 0; i < 5; i++)
        cout<< arr[i] << "\n";
    cout<< "\n";

    next_permutation(v.begin(), v.end());
    next_permutation(v.begin(), v.end());
    for (auto &val: v)
        cout<< val << "\n";

    // sometimes these two useful simple macros are used
    cout<< "\nUseful macros:" << "\n";
    printf("min(10, 7) = %d\n", min(10, 7));
    printf("max(10, 7) = %d\n", max(10, 7));

    return 0;
}
