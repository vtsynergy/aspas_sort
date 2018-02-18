# aspas_sort: Parallel Sorting Kernels Based on the Automatic SIMDIZation Frameworks (ASPaS) for x86 Platforms 
This repository provides parallel sort kernels with AVX, AVX2, and IMCI instruction sets for multicore CPUs and manycore MICs (Xeon Phis). The IMCI version can be easily ported to AVX-512 to execute on newer platforms, e.g., Intel Knights Landing. The data reordering codes are created based on our proposed **ASPaS** framework tool.  More details about the kernels and code generation framework can be found in our papers (below).

* Contact Email: kaixihou@vt.edu


## Citing Our Work:
1. A Framework for the Automatic Vectorization of Parallel Sort on x86-based Processors
Kaixi Hou, Hao Wang, Wu-chun Feng
In IEEE Transactions on Parallel and Distributed Systems. (TPDS), 
Accepted to the future issue in 2018.
    * Bibtex:  
    @InProceedings{Hou:sortext,  
        author =    {Hou, Kaixi and Wang, Hao and Feng, Wu-chun},  
        title =     {A Framework for the Automatic Vectorization of Parallel Sort on x86-based Processors},  
        booktitle = {IEEE Transactions on Parallel and Distributed Systems (TPDS)},  
        year =  {2018},}

2. ASPaS: A Framework for Automatic SIMDIZation of Parallel Sorting on x86-based Many-core Processors
Kaixi Hou, Hao Wang, Wu-chun Feng
In Proceedings of the 29th International Conference on Supercomputing (ICS), 
Newport Beach/Irvine, CA, USA,
June 2015.
    * Bibtex:  
    @InProceedings{Hou:aspassort,  
        author =    {Hou, Kaixi and Wang, Hao and Feng, Wu-chun},  
        title =     {ASPaS: A Framework for Automatic SIMDIZation of Parallel Sorting on x86-based Many-core Processors},  
        booktitle = {29th International Conference on Supercomputing (ICS)},  
        address =   {Newport Beach/Irvine, CA, USA},  
        month = {June},  
        year =  {2015},}

## Usage:
All the sort codes are wrapped in aspas::sort() and aspas::sort_key() for single-threaded SIMD version and aspas::parallel_sort() and aspas::parallel_sort_key() for multi-threaded SIMD version. The usage of them are demonstrated in the testsort.cpp in the src directory. The Makefile lists different vector ISAs to compile the codes and the autorun.sh shows how to execute the codes.

The following shows how to run the test codes using AVX2 for CPUs.
```
$ make ISA=avx2
```
After compilation, run the executable to sort 10000 integers (i) as: 
```
$ ./testsort.out -t i -s 10000
```

Simply put, you need to include the aspas.h to use the aspas sort (**aspas::sort**). Currently, the multi-threaded version is based on POSIX threads and we plan to provide OpenMP version in the future. 

## License: 
Please refer to the included LICENSE file.


