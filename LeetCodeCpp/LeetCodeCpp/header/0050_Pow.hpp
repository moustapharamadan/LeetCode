#pragma once
#include <vector>

namespace LEETCODE_0050 {
    class Solution {
    public:
        double myPow(double x, long int n) {
            if (n > 0)
                return myPositivePow(x, n);
            else
                return 1. / myPositivePow(x, -1 * n);
        }
    private:
        double myPositivePow(double x, long int n) {
            if (0 == n)
                return 1;
            if (1 == n)
                return x;
            if (0 == n % 2)
                return myPositivePow(x * x, n / 2);
            else
                return myPositivePow(x * x, n / 2) * x;
        }
    };
}
