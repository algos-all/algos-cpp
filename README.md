# Classic CS Algorithms in CPP

Unit tests are written with Boost.Test library. Run them like so:

```
mkdir build
cd build
cmake .. && make && ctest
```

To run a specific test unit, say binary search tests, drop the `test_` and run:

```
ctest -R binsearch
```

Alternatively, run the file directly: `./tests/test_binsearch`