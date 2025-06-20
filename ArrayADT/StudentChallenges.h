#ifndef STUDENTCHALLENGES_H
#define STUDENTCHALLENGES_H
#include "arrayADT.h"
namespace solutions {
    template<int size>
    int missingNumberInSortedUsingFormula(const arrayADT<int, size> &A) {
        int formula = A.getLength() * (A.getLength() + 1) / 2;
        int sum = A.accumulate();
        return formula - sum;
    }
}
#endif //STUDENTCHALLENGES_H
