#include<bits/stdc++.h>
using namespace std;

int main()
{
    // note: we don't have to use .clear() if we have just initialized the set/map
    set<int> used_values; // used_values.clear()
    map<string, int> mapper; // mapper.clear()
    int i;

    // suppose we enter these 7 name-score pairs below
    /*
    john 78
    billy 69
    andy 80
    steven 77
    felix 82
    grace 75
    martin 81
    */

    mapper["john"] = 78; used_values.insert(78);
    mapper["billy"] = 69; used_values.insert(69);
    mapper["andy"] = 80; used_values.insert(80);
    mapper["steven"] = 77; used_values.insert(77);
    mapper["felix"] = 82; used_values.insert(82);
    mapper["grace"] = 75; used_values.insert(75);
    mapper["martin"] = 81; used_values.insert(81);

    // iterating through the content of mapper will give a sorted output
    // based on keys
    for (auto &[key, value] : mapper) // c++17
    {
        printf("%s %d\n", key.c_str(), value);
    }

    // map can also be used like this
    printf("Steven's score is %d and Grace's score is %d\n", mapper["steven"], mapper["grace"]);
    printf("----------------\n");

    // interesting usage of lower_bound and upper_bound
    // display data between ["f".."m") ('felix' is included, 'martin' is excluded)
    for (auto it = mapper.lower_bound("f"); it != mapper.lower_bound("m"); it++)
    {
        printf("%s %d\n", it->first.c_str(), it->second);
    }

    // O(log n) search, found
    printf("%d\n", *used_values.find(77));

    // returns [69, 75] (these two are before 77 in the inorder traversal of the BST)
    for (auto it = used_values.begin(); it != used_values.lower_bound(77); it++)
    {
        printf("%d\n", *it);
    }
    printf("\n");
    // returns [77, 78, 80, 81, 82] (these five are equal or after 77 in the inorder
    // traversal of the BST)
    for (auto it = used_values.lower_bound(77); it != used_values.end(); it++)
        printf("%d\n", *it);
    printf("\n");

    if (used_values.find(79) == used_values.end())
        printf("79 not found\n");

    return 0;
}
