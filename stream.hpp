#ifndef STREAM_HPP
#define STREAM_HPP

#include <vector>
#include <functional>

namespace stream {
    template <typename T>
    class fcall_stream {
    public:
        fcall_stream() {
        }

        fcall_stream& operator>>(std::function<T(T)> x) {
            functions.push_back(x);
            return *this;
        }

        fcall_stream& operator() (T x) {
            first_arg = x;
            return *this;
        }

        T call() {
            T ans = first_arg;
            for (auto f : functions) {
                ans = f(ans);
            }
            return ans;
        }

        T call(T x) {
            first_arg = x;
            return call();
        }

    private:
        T first_arg;
        std::vector<std::function<T(T)>> functions;
    };

};



#endif /* end of include guard: STREAM_HPP */
