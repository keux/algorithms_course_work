#include <algorithm>
#include <cstdint>
#include <iostream>
#include <list>
#include <sstream>
#include <vector>

const uint64_t inf = 1000000000000000000;

class BigNumber {
 public:
    static constexpr uint64_t pow = 18;

    explicit BigNumber(uint64_t value) {
        if (value < inf) {
            digits_ = {value};
        } else {
            digits_ = {value % inf, value / inf};
        }
    }

    BigNumber operator+(const BigNumber& other) const {
        BigNumber result = *this;

        if (other.digits_.size() > result.digits_.size()) {
            result.digits_.resize(other.digits_.size());
        }

        uint64_t buffer = 0;
        for (size_t i = 0; i < result.digits_.size(); ++i) {
            uint64_t& digit = result.digits_[i];
            if (i < other.digits_.size()) {
                digit += other.digits_[i] + buffer;
            } else {
                if (buffer == 0) {
                    break;
                }
                digit += buffer;
            }
            buffer = digit / inf;
            digit %= inf;
        }
        if (buffer) {
            result.digits_.push_back(buffer);
        }

        return result;
    }

    std::string make_str() const {
        std::stringstream ss;
        bool first = true;
        for (auto it = digits_.rbegin(); it != digits_.rend(); ++it) {
            const std::string digit = std::to_string(*it);
            if (!first) {
                for (size_t i = 0; i < pow - digit.length(); ++i) {
                    ss << "0";
                }
            }
            first = false;
            ss << digit;
        }
        return ss.str();
    }

 private:
    std::vector<uint64_t> digits_;
};


typedef std::list<std::string> elems;
typedef std::vector<elems> hash;


hash make_table(size_t n) {
    hash table(n + 1);
    BigNumber prev(0), cur(1);
    while (true) {
        BigNumber next = prev + cur;
        std::string repr = next.make_str();
        if (repr.length() > n) {
            break;
        }
        table[repr.size()].push_back(std::move(repr));
        prev = std::move(cur);
        cur = std::move(next);
    }

    return table;
}
int main() {
    const hash fib = make_table(5000);
    std::string number;
    size_t n;
    std::cin >> n;

    for (size_t i = 0; i != n; ++i) {
        std::cin >> number;
        const elems& bin = fib[number.size()];
        if (std::find(bin.begin(), bin.end(), number) != bin.end()) {
            std::cout << "Yes\n";
        } else {
            std::cout << "No\n";
        }
    }
    return 0;
}
