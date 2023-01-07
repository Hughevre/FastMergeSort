# FastMergeSort - project overview
This repository contains the Fast Merge Sort (FMS) algorithm implementation which is the solution to the task BK7: 

Implement a mergesort algorithm by parallelizing the primes multiple table divisions. This algorithm divides the array into two parts, sorts each part recursively, and a then it loops through both already sorted parts, combining them into a sorted array. The size of the array should be chosen so that the calculations take at least a few seconds.

Tasks to be performed within the project

1. Write a sequential program, run it, do tests. Parallelize your program using OpenMP directives on any machine with a multi-core processor, do tests.
    - *Seq or *seq- sequential part
    - *OMP or *omp - paraller part

2. Distribute (with parallelize) your program using either MPI or gRPC on the same machine.

# Tech/framework used
- VS Code (Extensions: C/C++, C/C++ Extension Pack, CMake, CMake Tools, omp-pragma)
- Ubuntu 22.04 (for win)
- WSL 2 (for win)
- Catch2
- Gcov

# Tests screenshots
[Test result for fast merge sort - sequential and paraller](https://github.com/Hughevre/FastMergeSort/blob/main/screenshots/FastMergeSortTestSqlOMP.jpg.png)

# Download
git clone https://github.com/Hughevre/FastMergeSort

# For Windows users
VS Code: required 'Ubuntu-22.04' and extensions

[Command Palette] 'New WSL Windows using Distro...'

[Command Palette] 'Ubuntu-22.04'

Open Folder -> [Command Palette] /mnt/c/Users/{Select path where the folder is located}

[Lower bar] Build -> [Command Palette] 'CMake build' (if '*/tests/FMSTests: No such file or directory' then use CMake [Command Palette] 'CMake Clean Rebuild')

[Lower bar] Run -> [Command Palette] 'GCC 11.3.0. x86_64 linux_gnu'
