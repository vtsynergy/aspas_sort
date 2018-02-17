# aspas_sort: Parallel Sorting Kernels Based on the Automatic SIMDIZation Frameworks (ASPaS) for x86 Platforms 
This repository provides parallel sort kernels with AVX, AVX2, and IMCI instruction sets for multicore CPUs and manycore MICs (Xeon Phis). The IMCI version can be easily ported to AVX-512 to execute on newer platforms, e.g., Intel Knights Landing. The data reordering codes are created based on our proposed **ASPaS** framework tool.  More details about the kernels and code generation framework can be found in our papers (below).

* Contact Email: kaixihou@vt.edu


## Citing Our Work:
* PlainText:  
A Framework for the Automatic Vectorization of Parallel Sort on x86-based Processors
Kaixi Hou, Hao Wang, Wu-chun Feng
In IEEE Transactions on Parallel and Distributed Systems. (TPDS), 
Accepted to the future issue in 2018.
* Bibtex:  
@InProceedings{Hou:sortext,  
    author =    {Hou, Kaixi and Wang, Hao and Feng, Wu-chun},  
    title =     {A Framework for the Automatic Vectorization of Parallel Sort on x86-based Processors},  
    booktitle = {IEEE Transactions on Parallel and Distributed Systems (TPDS)},  
    year =  {2018},  
}

* PlainText:  
ASPaS: A Framework for Automatic SIMDIZation of Parallel Sorting on x86-based Many-core Processors
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
    year =  {2015},  
}

## Usage:
You can make changes to the Makefile accordingly. Especially, you need to change the ARCH according to your GPU platform. For example, if you are using the P100, you should update ARCH to 61. The main.cu contains an example of how to use it.

The following shows how to run the example codes.
```
$ make
```
After compilation, run the executable as: 
```
$ ./main.out
```

To use the segmented sort (**bb_segsort**), you just need to include the bb_sort.h (with other *.h files).  Note, bb_segsort utilizes an unstable sorting network as the building block; thus, equivalent elements are not guaranteed to keep the original relative order. We plan to provide a version to support stable sort in the future. 

## License: 
Please refer to the included LICENSE file.


