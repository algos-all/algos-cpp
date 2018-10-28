# Classic CS Algorithms in CPP

[![Build Status](https://travis-ci.org/alisianoi/algos-cpp.svg?branch=master)](https://travis-ci.org/alisianoi/algos-cpp)

## How to set up?

First, install the [conan](https://conan.io/) package manager for your system. Then build and run the unit tests like so:

```sh
mkdir build && cd build
conan install .. && cmake ..
ctest
```

Unit tests are written with Boost.Test library. To run a specific test unit, say binary search tests, drop the `test_` and run:

```sh
ctest --verbose -R binsearch
```

Alternatively, run the file directly:

```sh
./tests/test_binsearch
```
