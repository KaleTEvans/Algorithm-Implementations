// You are climning a staircase, which takes n steps to get to the top. You can either climb 1 or 2 steps each time
// Return the total step comnbinations

/*
    Ex. n = 3 would have 3 combinations: 1+1, 1+2, 2+1
*/

// After writing the problem out, it seems as though, after 1 and 2, each amount of steps is the total of the previous two step combinations
// For example, 4 steps has 5 cobinations, 5 steps has 8 combinations, and 6 steps has 13. So 13 = 5+8
// This is similar to a fibonacci sequence, so a recursive solution would be the simplest approach

#include <iostream>

using namespace std;

int climbStairs(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;

    return climbStairs(n-1) + climbStairs(n-2);
}

// As you reach high numbers, this may end up taking a lot of time, the following iterative approach is a bit quicker

int climbStairsIt(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;

    int temp;
    int a = 1;
    int b = 2;

    for (int i=3; i < n; i++) {
        temp = b;
        b = b + a;
        a = temp;
    }

    return a+b;
}
  
int main() {
    int n = 20;
    cout << climbStairs(n);
}