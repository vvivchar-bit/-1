#include <iostream>
#include <type_traits>

template <typename T1, typename T2>
class NumberPair {
    static_assert(std::is_arithmetic_v<T1>, "T1 must be a numeric type");
    static_assert(std::is_arithmetic_v<T2>, "T2 must be a numeric type");

private:
    T1 first;
    T2 second;

public:
    NumberPair() : first{}, second{} {}
    NumberPair(const T1& a, const T2& b) : first(a), second(b) {}

    const T1& getFirst() const { return first; }
    const T2& getSecond() const { return second; }

    void setFirst(const T1& a) { first = a; }
    void setSecond(const T2& b) { second = b; }

    auto sum() const { return first + second; }
    auto product() const { return first * second; }

    void print() const {
        std::cout << "(" << first << ", " << second << ")";
    }
};

int main() {
    NumberPair<int, double> p1(10, 2.5);
    NumberPair<long long, short> p2(10000000000LL, 7);

    std::cout << "p1 = "; p1.print();
    std::cout << "  sum=" << p1.sum() << "  prod=" << p1.product() << "\n";

    std::cout << "p2 = "; p2.print();
    std::cout << "  sum=" << p2.sum() << "  prod=" << p2.product() << "\n";

    return 0;
}
