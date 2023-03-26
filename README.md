
This project implements a Haskell program that calculates the sum of Euler totient values from 2 to n using parallelization with the Control.Parallel.Strategies library.

To build the project, first make sure that you have Haskell and Cabal installed on your machine. Then, navigate to the project directory in your terminal and run the following command:

```cabal build```

This will build the executable file for the program.
To run the program, use the following command, replacing [n] with the upper limit of the range:

```./dist-newstyle/build/x86_64-linux/ghc-9.0.1/euler-totient-parallel-0.1.0.0/x/euler-totient-parallel/build/euler-totient-parallel/euler-totient-parallel [n]```

The program will then print the sum of Euler totient values from 2 to [n].
To analyze the performance of the program, you can use profiling tools such as +RTS -p or +RTS -s. These tools provide information about the program's memory usage, garbage collection, and execution time.

The sequential version of the program can be run using the following command:

```./dist-newstyle/build/x86_64-linux/ghc-9.0.1/euler-totient-sequential-0.1.0.0/x/euler-totient-sequential/build/euler-totient-sequential/euler-totient-sequential [n]```

This program calculates the sum of Euler totient values in a single thread without parallelization.
During profiling, the phi function was identified as a hotspot, as it is called multiple times with different input values. 
To optimize this, we can use memoization to cache the results of previous computations and reuse them in subsequent calls. 
Additionally, we can experiment with different parallelization strategies and chunk sizes to determine the optimal configuration for our machine and input data.
