#include <iostream>
#include "stream.hpp"

int work(int x) {
    return x+3;
}

int work2(int x) {
    return x*2;
}

int main(int argc, char const *argv[]) {
    stream::fcall_stream<int> fs;
    fs(10) >> work >> work2;
    std::cout << fs.call() << std::endl;
    return 0;
}
