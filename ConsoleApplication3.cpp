#include <iostream>
#include <vector>
#include <string>

// Template: find all elements in [low, high]
template <typename T>
std::vector<T> findInRange(const T* arr, std::size_t n, const T& low, const T& high) {
    std::vector<T> result;
    for (std::size_t i = 0; i < n; ++i) {
        if (!(arr[i] < low) && !(high < arr[i])) { // low <= arr[i] <= high
            result.push_back(arr[i]);
        }
    }
    return result;
}

template <typename T>
void printVec(const std::vector<T>& v) {
    for (const auto& x : v) std::cout << x << " ";
    std::cout << "\n";
}

int main() {
    // int
    int ai[] = { -5, 2, 7, 10, 3, 0, 15 };
    auto ri = findInRange(ai, sizeof(ai) / sizeof(ai[0]), 0, 10);
    std::cout << "int in [0..10]: ";
    printVec(ri);

    // double
    double ad[] = { 1.2, -3.5, 4.4, 10.0, 9.99, 2.0 };
    auto rd = findInRange(ad, sizeof(ad) / sizeof(ad[0]), 2.0, 10.0);
    std::cout << "double in [2.0..10.0]: ";
    printVec(rd);

    // string (lexicographic range)
    std::string as[] = { "apple", "banana", "cherry", "avocado", "blueberry", "date" };
    auto rs = findInRange(as, sizeof(as) / sizeof(as[0]),
        std::string("banana"), std::string("date"));
    std::cout << "string in [banana..date]: ";
    printVec(rs);

    return 0;
}
