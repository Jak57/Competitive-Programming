#include <bits/stdc++.h>
using namespace std;

typedef pair<int, string> is;

int main()
{
    // suppose we enter these money-name pair below
    /*
    100 john
    10 billy
    20 andy
    100 steven
    70 felix
    2000 grace
    70 martin
    */
    priority_queue<is> pq;
    pq.push(make_pair(100, "john")); // insertion in O(log n)
    pq.push(make_pair(10, "billy"));
    pq.push(make_pair(20, "andy"));

    pq.push(make_pair(100, "steven"));
    pq.push(make_pair(70, "felix"));
    pq.push(make_pair(2000, "grace"));
    pq.push(make_pair(70, "martin"));

    // priority queue will arrange item in heap based
    // on the first key in pair, which is money (largest first)
    // if first key tie, then on second key, which is name (largest first)

    // let's print out top 3 persons with most money
    // O(1) to access the top/max element
    auto &[score, name] = pq.top();
    printf("%s has %d $\n", name.c_str(), score);
    // O(log n) to delete the top element and
    // repair the structure

    // [score, name] is still binded to pq.top() as we use '&' above
    pq.pop();
    printf("%s has %d $\n", name.c_str(), score);
    pq.pop();
    printf("%s has %d $\n", name.c_str(), score);



    return 0;
}
