#include <bits/stdc++.h>
using namespace std;

#define setBit(S, j) (S |= (1 << j))
#define isOn(S, j) (S & (1 << j))
#define clearBit(S, j) (S &= (~(1 << j)))

#define toggleBit(S, j) (S ^= (1 << j))
#define lowBit(S) (S & (-S))
#define setAll(S, n) (S = (1 << n) - 1)

// in binary representation
void printSet(int vS)
{
    printf("S = %2d = ", vS);
    stack<int> st;

    while (vS) {
        st.push(vS % 2);
        vS /= 2;
    }

    // to reverse the print order
    while (!st.empty()) {
        printf("%d", st.top());
        st.pop();
    }
    printf("\n");

}

int main()
{
    int S, T;
    printf("1. Representation (all indexing are 0-based and counted from right)\n");
    S = 34;
    printSet(S);
    printf("\n");

    printf("2. Multiply S by 2, then divide S by 4 (2x2), then by 2\n");
    S = 34;
    printSet(S);
    S = S << 1;
    printSet(S);

    S = S >> 2;
    printSet(S);
    S = S >> 1;
    printSet(S);
    printf("\n");

    printf("3. Set/turn on the 3-rd item of the set\n");
    S = 34;
    printSet(S);

    setBit(S, 3);
    printSet(S);
    printf("\n");

    printf("4. Check if the 3-rd and then 2-nd item of the set is on?\n");
    S = 42;
    printSet(S);
    T = isOn(S, 3);

    printf("T = %d, %s\n", T, T ? "ON" : "OFF");
    T = isOn(S, 2);
    printf("T = %d, %s\n", T, T ? "ON" : "OFF");
    printf("\n");

    printf("5. Clear/turn off the 1-st item of the set\n");
    S = 42;
    printSet(S);

    clearBit(S, 1);
    printSet(S);
    printf("\n");

    printf("6. To toggle the the 2-nd and 3-rd item of the set\n");
    S = 40;
    printSet(S);
    toggleBit(S, 2);

    printSet(S);
    toggleBit(S, 3);
    printSet(S);
    printf("\n");

    printf("7. Check the first bit from right that is on\n");
    S = 40;
    printSet(S);
    T = lowBit(S);
    printSet(T);

    S = 52;
    printSet(S);
    T = lowBit(S);
    printSet(T);
    printf("\n");

    printf("8. To turn on all bits in a set of size n = 6\n");
    setAll(S, 6);
    printSet(S);

    return 0;
}
