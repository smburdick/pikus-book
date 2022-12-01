#include "01.h"

bool compare(const char * s1, const char* s2, unsigned int l);

int main() {
    constexpr unsigned int L = 1 << 18, N = 1 << 14;
    unique_ptr<char[]> s(new char[L]);
    vector<const char*> vs(N);
    minstd_rand rgen;
    ::memset(s.get(), 'a', N * sizeof(char));
    for (unsigned int i = 0; i < L / 1024; ++i) {
        s[rgen() % (L - 1)] = 'a' + (rgen() % ('z' - 'a' + 1));
    }
    s[L - 1] = 0;
    for (unsigned int i = 0; i < N; ++i) {
        vs[i] = &s[rgen() % (L - 1)];
    }
    // prepare the string
    size_t count = 0;
    system_clock::time_point t1 = system_clock::now();
    std::sort(vs.begin(), vs.end(),
        [&](const char* a, const char* b) {
            ++count;
            return compare(a, b, L);
        });
    system_clock::time_point t2 = system_clock::now();
    cout << "Sort time: " << duration_cast<milliseconds>(t2 - t1).count() <<  "ms (" << count << " comparisons)" << endl;

    return 0;
}
