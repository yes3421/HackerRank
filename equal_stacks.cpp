#include <algorithm>
#include <cstdlib>
#include <deque>
#include <functional>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

int equalStacks(std::vector<int>& h1, std::vector<int>& h2, std::vector<int>& h3)
{
    std::deque<int> dq1(h1.begin(), h1.end());
    std::deque<int> dq2(h2.begin(), h2.end());
    std::deque<int> dq3(h3.begin(), h3.end());

    std::vector<int> heights{
        std::accumulate(dq1.begin(), dq1.end(), 0),
        std::accumulate(dq2.begin(), dq2.end(), 0),
        std::accumulate(dq3.begin(), dq3.end(), 0)
    };

    while (
        std::adjacent_find(
            heights.begin(), heights.end(),
            std::not_equal_to<int>())
        != heights.end()
    ) {
        int min_height = *std::min_element(heights.begin(), heights.end());
        if (*(heights.begin()) > min_height) {
            *(heights.begin()) -= dq1.front();
            dq1.pop_front();
        }
        if (*(heights.begin() + 1) > min_height) {
            *(heights.begin() + 1) -= dq2.front();
            dq2.pop_front();
        }
        if (*(heights.begin() + 2) > min_height) {
            *(heights.begin() + 2) -= dq3.front();
            dq3.pop_front();
        }
    }
    return *(heights.begin());
}

int main()
{
    std::vector<int> test1{3, 2, 1, 1, 1};
    std::vector<int> test2{4, 3, 2};
    std::vector<int> test3{1, 1, 4, 1};

    std::cout
    << std::boolalpha
    << equalStacks(test1, test2, test3)
    << '\n';

    return EXIT_SUCCESS;
}
