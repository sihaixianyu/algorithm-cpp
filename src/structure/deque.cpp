#include <fmt/core.h>

#include <iostream>
#include <vector>

using namespace std;

#define DEFAULT_CAP 8

template <typename T> class Deque {
private:
    T* data;
    size_t cap;
    size_t len;
    size_t front;
    size_t back;

public:
    Deque()
        : data(new T[DEFAULT_CAP]), cap(DEFAULT_CAP), len(0), front(0),
          back(0) {}
    ~Deque() { delete[] data; }

    void resize(size_t cap);
};

int main() { cout << "Deque" << endl; }
