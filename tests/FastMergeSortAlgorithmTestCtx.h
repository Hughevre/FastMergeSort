#ifndef FAST_MERGE_SORT_ALGORITHM_TEST_CTX_H
#define FAST_MERGE_SORT_ALGORITHM_TEST_CTX_H

#include <memory>
#include <vector>
#include "../inc/FastMergeSortAlgorithm.h"

class FastMergeSortAlgorithmTestCtx {
    public:
        explicit FastMergeSortAlgorithmTestCtx(std::unique_ptr<FastMergeSortAlgorithm>&& algorithm_flavour = {});

        void SetAlgorithm(std::unique_ptr<FastMergeSortAlgorithm>&& algorithm_flavour);
        void RunPhase(std::vector<int>& numbers_array,
                      unsigned int      left_index,
                      unsigned int      right_index) const;

    private:
        /**
        * @var algorithm_flavour_ The Context maintains a reference to one of the FMS
        * objects. The Context does not know the concrete class of the FMS. It
        * should work with all favoures via the FMS interface.
        */
        std::unique_ptr<FastMergeSortAlgorithm> algorithm_flavour_;
};

#endif // FAST_MERGE_SORT_ALGORITHM_TEST_CTX_H