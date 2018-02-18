/*
* (c) 2015 Virginia Polytechnic Institute & State University (Virginia Tech)   
*                                                                              
*   This program is free software: you can redistribute it and/or modify       
*   it under the terms of the GNU General Public License as published by       
*   the Free Software Foundation, version 2.1                                  
*                                                                              
*   This program is distributed in the hope that it will be useful,            
*   but WITHOUT ANY WARRANTY; without even the implied warranty of             
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the              
*   GNU General Public License, version 2.1, for more details.                 
*                                                                              
*   You should have received a copy of the GNU General Public License          
*                                                                              
*/

/**
 * @file testsort.cpp
 * Performs basic tests of sort.
 *
 * @author Kaixi Hou
 *
 */

#include <iostream>
#include "aspas.h"
#include "util/tools.h"
#include <getopt.h>

#define RANDOM_MAX array_size
#define RANDOM_MIN 0 
int main(int argc, char** argv)
{
    /** parsing program options */
    int opt;
    bool debug_flag = false;
    bool profile_flag = false;
    bool with_ptr_flag = false;
    bool with_ptr_flag_long = false;
    int array_size = 10;
    char type = 'i';
    int thread_num = -1;
    while((opt = getopt(argc, argv, "ds:pt:n:cl")) != -1) {
        switch(opt) {
            case 'd':
                debug_flag = true;
                break;
            case 'p':
                profile_flag = true;
                break;
            case 't':
                type = optarg[0];
                break;
            case 'n':
                thread_num = atoi(optarg);
                break;
            case 's':
                array_size = atoi(optarg);
                break;
            case 'c':
                with_ptr_flag = true;
                break;
            case 'l':
                with_ptr_flag_long = true;
                break;
            default:
                std::cerr << "Usage" << argv[0] << " [-p profiling mode (off)] [-d debug mode (off)]"  
                        " [-s array size (10)] [-t data type (i)] [-n thread number (-1)]"
                        " [-c key-data pair mode (off)] [-l in key-data mode, data is 64-bit (off)]" << std::endl;
                exit(EXIT_FAILURE);
        }
    }

    unsigned int r_seed;
    r_seed = 1; // (unsigned int) time(NULL);
    // working on the single-threaded version
    if(thread_num == -1)
    {
        if(with_ptr_flag)
        {
            switch(type)
            {
                case 'i':
                {
                    if(with_ptr_flag_long) 
                    {
                        int *test_array = new int[array_size];
                        int *copy_test_array = new int[array_size]; // for verifying the results 
                        long *id_array   = new long[array_size];

                        srand(r_seed);
                        for(int i = 0; i < array_size; i++) {
                            test_array[i] = (rand() % (RANDOM_MAX + 1 - RANDOM_MIN)) + RANDOM_MIN;
                            copy_test_array[i] = test_array[i];
                            id_array[i] = i;
                        }

                        double tstart, tstop, ttime; 
                        tstart = util::dtime();

                        aspas::sort_key(test_array, id_array, array_size);

                        tstop = util::dtime();

                        ttime = tstop - tstart;
                        std::cerr << "1\tint\t"<<array_size<<"\ttime\t" << ttime;

                        if(util::check_sorted_key(copy_test_array, id_array, array_size))
                            std::cout << "\tlong_id_passed";
                        else
                            std::cout << "\tlong_id_failed";

                        if(util::check_sorted(test_array, array_size))
                            std::cout << "\tkey_passed" << std::endl;
                        else
                            std::cout << "\tkey_failed" << std::endl;

                        delete[] test_array;
                        delete[] copy_test_array;
                        delete[] id_array;
                    }
                    else
                    {
                        int *test_array = new int[array_size];
                        int *copy_test_array = new int[array_size]; // for verifying the results 
                        int *id_array   = new int[array_size];

                        srand(r_seed);
                        for(int i = 0; i < array_size; i++) {
                            test_array[i] = (rand() % (RANDOM_MAX + 1 - RANDOM_MIN)) + RANDOM_MIN;
                            copy_test_array[i] = test_array[i];
                            id_array[i] = i;
                        }

                        double tstart, tstop, ttime; 
                        tstart = util::dtime();

                        aspas::sort_key(test_array, id_array, array_size);

                        tstop = util::dtime();

                        ttime = tstop - tstart;
                        std::cerr << "1\tint\t"<<array_size<<"\ttime\t" << ttime;

                        if(util::check_sorted_key(copy_test_array, id_array, array_size))
                            std::cout << "\tid_passed";
                        else
                            std::cout << "\tid_failed";

                        if(util::check_sorted(test_array, array_size))
                            std::cout << "\tkey_passed" << std::endl;
                        else
                            std::cout << "\tkey_failed" << std::endl;

                        delete[] test_array;
                        delete[] copy_test_array;
                        delete[] id_array;
                    }
                    break;
                }
                case 'f':
                {
                    if(with_ptr_flag_long) 
                    {
                        float* test_array = new float[array_size];
                        float *copy_test_array = new float[array_size]; // for verifying the results 
                        long *id_array   = new long[array_size];

                        srand(r_seed);
                        for(int i = 0; i < array_size; i++) {
                            test_array[i] = ((float)rand() / RAND_MAX)*(RANDOM_MAX - RANDOM_MIN) + RANDOM_MIN;
                            copy_test_array[i] = test_array[i];
                            id_array[i] = i;
                        }
                        double tstart, tstop, ttime; 
                        tstart = util::dtime();

                        aspas::sort_key(test_array, id_array, array_size);

                        tstop = util::dtime();
                        ttime = tstop - tstart;
                        std::cerr << "1\tfloat\t"<<array_size<<"\ttime\t" << ttime;

                        if(util::check_sorted_key(copy_test_array, id_array, array_size))
                            std::cout << "\tlong_id_passed";
                        else
                            std::cout << "\tlong_id_failed";

                        if(util::check_sorted(test_array, array_size))
                            std::cout << "\tkey_passed" << std::endl;
                        else
                            std::cout << "\tkey_failed" << std::endl;
                        delete[] test_array;
                        delete[] copy_test_array;
                        delete[] id_array;
                    }
                    else
                    {
                        float* test_array = new float[array_size];
                        float *copy_test_array = new float[array_size]; // for verifying the results 
                        int *id_array   = new int[array_size];

                        srand(r_seed);
                        for(int i = 0; i < array_size; i++) {
                            test_array[i] = ((float)rand() / RAND_MAX)*(RANDOM_MAX - RANDOM_MIN) + RANDOM_MIN;
                            copy_test_array[i] = test_array[i];
                            id_array[i] = i;
                        }
                        double tstart, tstop, ttime; 
                        tstart = util::dtime();

                        aspas::sort_key(test_array, id_array, array_size);

                        tstop = util::dtime();
                        ttime = tstop - tstart;
                        std::cerr << "1\tfloat\t"<<array_size<<"\ttime\t" << ttime;

                        if(util::check_sorted_key(copy_test_array, id_array, array_size))
                            std::cout << "\tid_passed";
                        else
                            std::cout << "\tid_failed";

                        if(util::check_sorted(test_array, array_size))
                            std::cout << "\tkey_passed" << std::endl;
                        else
                            std::cout << "\tkey_failed" << std::endl;
                        delete[] test_array;
                        delete[] copy_test_array;
                        delete[] id_array;
                    }
                    break;
                }
                case 'd':
                {
                    if(with_ptr_flag_long)  // with long index
                    {
                        double* test_array = new double[array_size];
                        double *copy_test_array = new double[array_size]; // for verifying the results 
                        long *id_array   = new long[array_size];

                        srand(r_seed);
                        for(int i = 0; i < array_size; i++) {
                            test_array[i] = ((double)rand() / RAND_MAX)*(RANDOM_MAX - RANDOM_MIN) + RANDOM_MIN;
                            copy_test_array[i] = test_array[i];
                            id_array[i] = i;
                        }
                        double tstart, tstop, ttime; 
                        tstart = util::dtime();

                        aspas::sort_key(test_array, id_array, array_size);

                        tstop = util::dtime();
                        ttime = tstop - tstart;
                        std::cerr << "1\tdouble\t"<<array_size<<"\ttime\t" << ttime;

                        if(util::check_sorted_key(copy_test_array, id_array, array_size))
                            std::cout << "\tlong_id_passed";
                        else
                            std::cout << "\tlong_id_failed";

                        if(util::check_sorted(test_array, array_size))
                            std::cout << "\tkey_passed" << std::endl;
                        else
                            std::cout << "\tkey_failed" << std::endl;
                        delete[] test_array;
                        delete[] copy_test_array;
                        delete[] id_array;
                    }
                    else // with int index
                    {
                        double* test_array = new double[array_size];
                        double *copy_test_array = new double[array_size]; // for verifying the results 
                        int *id_array   = new int[array_size];

                        srand(r_seed);
                        for(int i = 0; i < array_size; i++) {
                            test_array[i] = ((double)rand() / RAND_MAX)*(RANDOM_MAX - RANDOM_MIN) + RANDOM_MIN;
                            copy_test_array[i] = test_array[i];
                            id_array[i] = i;
                        }
                        double tstart, tstop, ttime; 
                        tstart = util::dtime();

                        aspas::sort_key(test_array, id_array, array_size);

                        tstop = util::dtime();
                        ttime = tstop - tstart;
                        std::cerr << "1\tdouble\t"<<array_size<<"\ttime\t" << ttime;

                        if(util::check_sorted_key(copy_test_array, id_array, array_size))
                            std::cout << "\tid_passed";
                        else
                            std::cout << "\tid_failed";

                        if(util::check_sorted(test_array, array_size))
                            std::cout << "\tkey_passed" << std::endl;
                        else
                            std::cout << "\tkey_failed" << std::endl;
                        delete[] test_array;
                        delete[] copy_test_array;
                        delete[] id_array;
                    }
                    break;
                }
            }
        } 
        else // without ptr data
        {
            switch(type)
            {
                case 'i':
                {
                    int* test_array = new int[array_size];
                    srand(r_seed);
                    for(int i = 0; i < array_size; i++) {
                        test_array[i] = (rand() % (RANDOM_MAX + 1 - RANDOM_MIN)) + RANDOM_MIN;
                    }
                    double tstart, tstop, ttime; 
                    tstart = util::dtime();

                    aspas::sort(test_array, array_size);

                    tstop = util::dtime();
                    ttime = tstop - tstart;
                    std::cerr << "1\tint\t"<<array_size<<"\ttime\t" << ttime;

                    if(util::check_sorted(test_array, array_size))
                        std::cout << "\tpassed" << std::endl;
                    else
                        std::cout << "\tfailed" << std::endl;
                    delete[] test_array;
                    break;
                }
                case 'f':
                {
                    float* test_array = new float[array_size];
                    srand(r_seed);
                    for(int i = 0; i < array_size; i++) {
                        test_array[i] = ((float)rand() / RAND_MAX)*(RANDOM_MAX - RANDOM_MIN) + RANDOM_MIN;
                    }
                    double tstart, tstop, ttime; 
                    tstart = util::dtime();

                    aspas::sort(test_array, array_size);

                    tstop = util::dtime();
                    ttime = tstop - tstart;
                    std::cerr << "1\tfloat\t"<<array_size<<"\ttime\t" << ttime;

                    if(util::check_sorted(test_array, array_size))
                        std::cout << "\tpassed" << std::endl;
                    else
                        std::cout << "\tfailed" << std::endl;
                    delete[] test_array;
                    break;
                }
                case 'd':
                {
                    double* test_array = new double[array_size];
                    srand(r_seed);
                    for(int i = 0; i < array_size; i++) {
                        test_array[i] = ((double)rand() / RAND_MAX)*(RANDOM_MAX - RANDOM_MIN) + RANDOM_MIN;
                    }
                    double tstart, tstop, ttime; 
                    tstart = util::dtime();

                    aspas::sort(test_array, array_size);

                    tstop = util::dtime();
                    ttime = tstop - tstart;
                    std::cerr << "1\tdouble\t"<<array_size<<"\ttime\t" << ttime;

                    if(util::check_sorted(test_array, array_size))
                        std::cout << "\tpassed" << std::endl;
                    else
                        std::cout << "\tfailed" << std::endl;
                    delete[] test_array;
                    break;
                }
            }
        }
    } else // multi-threaded version
    {
        if(with_ptr_flag)
        {
            aspas::thread_num_init(thread_num);
            switch(type)
            {
                case 'i':
                {
                    if(with_ptr_flag_long)
                    {
                        int *test_array = new int[array_size];
                        int *copy_test_array = new int[array_size]; // for verifying the results 
                        long *id_array   = new long[array_size];

                        srand(r_seed);
                        for(int i = 0; i < array_size; i++) {
                            test_array[i] = (rand() % (RANDOM_MAX + 1 - RANDOM_MIN)) + RANDOM_MIN;
                            copy_test_array[i] = test_array[i];
                            id_array[i] = i;
                        }

                        double tstart, tstop, ttime; 
                        tstart = util::dtime();

                        aspas::parallel_sort_key(test_array, id_array, array_size);

                        tstop = util::dtime();

                        ttime = tstop - tstart;
                        std::cerr << thread_num <<"\tint\t"<<array_size<<"\ttime\t" << ttime;

                        if(util::check_sorted_key(copy_test_array, id_array, array_size))
                            std::cout << "\tlong_id_passed";
                        else
                            std::cout << "\tlong_id_failed";

                        if(util::check_sorted(test_array, array_size))
                            std::cout << "\tkey_passed" << std::endl;
                        else
                            std::cout << "\tkey_failed" << std::endl;

                        delete[] test_array;
                        delete[] copy_test_array;
                        delete[] id_array;
                    }
                    else
                    {
                        int *test_array = new int[array_size];
                        int *copy_test_array = new int[array_size]; // for verifying the results 
                        int *id_array   = new int[array_size];

                        srand(r_seed);
                        for(int i = 0; i < array_size; i++) {
                            test_array[i] = (rand() % (RANDOM_MAX + 1 - RANDOM_MIN)) + RANDOM_MIN;
                            copy_test_array[i] = test_array[i];
                            id_array[i] = i;
                        }

                        double tstart, tstop, ttime; 
                        tstart = util::dtime();

                        aspas::parallel_sort_key(test_array, id_array, array_size);

                        tstop = util::dtime();

                        ttime = tstop - tstart;
                        std::cerr << thread_num <<"\tint\t"<<array_size<<"\ttime\t" << ttime;

                        if(util::check_sorted_key(copy_test_array, id_array, array_size))
                            std::cout << "\tid_passed";
                        else
                            std::cout << "\tid_failed";

                        if(util::check_sorted(test_array, array_size))
                            std::cout << "\tkey_passed" << std::endl;
                        else
                            std::cout << "\tkey_failed" << std::endl;

                        delete[] test_array;
                        delete[] copy_test_array;
                        delete[] id_array;
                    }
                    break;
                }
                case 'f':
                {
                    if(with_ptr_flag_long)
                    {
                        float *test_array = new float[array_size];
                        float *copy_test_array = new float[array_size]; // for verifying the results 
                        long *id_array   = new long[array_size];

                        srand(r_seed);
                        for(int i = 0; i < array_size; i++) {
                            test_array[i] = ((float)rand() / RAND_MAX)*(RANDOM_MAX - RANDOM_MIN) + RANDOM_MIN;
                            copy_test_array[i] = test_array[i];
                            id_array[i] = i;
                        }

                        double tstart, tstop, ttime; 
                        tstart = util::dtime();

                        aspas::parallel_sort_key(test_array, id_array, array_size);

                        tstop = util::dtime();

                        ttime = tstop - tstart;
                        std::cerr << thread_num <<"\tfloat\t"<<array_size<<"\ttime\t" << ttime;

                        if(util::check_sorted_key(copy_test_array, id_array, array_size))
                            std::cout << "\tlong_id_passed";
                        else
                            std::cout << "\tlong_id_failed";

                        if(util::check_sorted(test_array, array_size))
                            std::cout << "\tkey_passed" << std::endl;
                        else
                            std::cout << "\tkey_failed" << std::endl;

                        delete[] test_array;
                        delete[] copy_test_array;
                        delete[] id_array;
                    }
                    else
                    {
                        float *test_array = new float[array_size];
                        float *copy_test_array = new float[array_size]; // for verifying the results 
                        int *id_array   = new int[array_size];

                        srand(r_seed);
                        for(int i = 0; i < array_size; i++) {
                            test_array[i] = ((float)rand() / RAND_MAX)*(RANDOM_MAX - RANDOM_MIN) + RANDOM_MIN;
                            copy_test_array[i] = test_array[i];
                            id_array[i] = i;
                        }

                        double tstart, tstop, ttime; 
                        tstart = util::dtime();

                        aspas::parallel_sort_key(test_array, id_array, array_size);

                        tstop = util::dtime();

                        ttime = tstop - tstart;
                        std::cerr << thread_num <<"\tfloat\t"<<array_size<<"\ttime\t" << ttime;

                        if(util::check_sorted_key(copy_test_array, id_array, array_size))
                            std::cout << "\tid_passed";
                        else
                            std::cout << "\tid_failed";

                        if(util::check_sorted(test_array, array_size))
                            std::cout << "\tkey_passed" << std::endl;
                        else
                            std::cout << "\tkey_failed" << std::endl;

                        delete[] test_array;
                        delete[] copy_test_array;
                        delete[] id_array;
                    }
                    break;
                }
                case 'd':
                {
                    if(with_ptr_flag_long)
                    {
                        double *test_array = new double[array_size];
                        double *copy_test_array = new double[array_size]; // for verifying the results 
                        long *id_array   = new long[array_size];

                        srand(r_seed);
                        for(int i = 0; i < array_size; i++) {
                            test_array[i] = ((double)rand() / RAND_MAX)*(RANDOM_MAX - RANDOM_MIN) + RANDOM_MIN;
                            copy_test_array[i] = test_array[i];
                            id_array[i] = i;
                        }

                        double tstart, tstop, ttime; 
                        tstart = util::dtime();

                        aspas::parallel_sort_key(test_array, id_array, array_size);

                        tstop = util::dtime();

                        ttime = tstop - tstart;
                        std::cerr << thread_num <<"\tdouble\t"<<array_size<<"\ttime\t" << ttime;

                        if(util::check_sorted_key(copy_test_array, id_array, array_size))
                            std::cout << "\tlong_id_passed";
                        else
                            std::cout << "\tlong_id_failed";

                        if(util::check_sorted(test_array, array_size))
                            std::cout << "\tkey_passed" << std::endl;
                        else
                            std::cout << "\tkey_failed" << std::endl;

                        delete[] test_array;
                        delete[] copy_test_array;
                        delete[] id_array;
                    }
                    else
                    {
                        double *test_array = new double[array_size];
                        double *copy_test_array = new double[array_size]; // for verifying the results 
                        int *id_array   = new int[array_size];

                        srand(r_seed);
                        for(int i = 0; i < array_size; i++) {
                            test_array[i] = ((double)rand() / RAND_MAX)*(RANDOM_MAX - RANDOM_MIN) + RANDOM_MIN;
                            copy_test_array[i] = test_array[i];
                            id_array[i] = i;
                        }

                        double tstart, tstop, ttime; 
                        tstart = util::dtime();

                        aspas::parallel_sort_key(test_array, id_array, array_size);

                        tstop = util::dtime();

                        ttime = tstop - tstart;
                        std::cerr << thread_num <<"\tdouble\t"<<array_size<<"\ttime\t" << ttime;

                        if(util::check_sorted_key(copy_test_array, id_array, array_size))
                            std::cout << "\tid_passed";
                        else
                            std::cout << "\tid_failed";

                        if(util::check_sorted(test_array, array_size))
                            std::cout << "\tkey_passed" << std::endl;
                        else
                            std::cout << "\tkey_failed" << std::endl;

                        delete[] test_array;
                        delete[] copy_test_array;
                        delete[] id_array;
                    }
                    break;
                }
            }
        }
        else // no index
        {
            aspas::thread_num_init(thread_num);
            switch(type)
            {
                case 'i':
                {
                    int* test_array = new int[array_size];
                    srand(r_seed);
                    for(int i = 0; i < array_size; i++) {
                        test_array[i] = (rand() % (RANDOM_MAX + 1 - RANDOM_MIN)) + RANDOM_MIN;
                    }
                    double tstart, tstop, ttime; 
                    tstart = util::dtime();

                    aspas::parallel_sort(test_array, array_size);

                    tstop = util::dtime();
                    ttime = tstop - tstart;
                    std::cerr << thread_num <<"\tint\t"<<array_size<<"\ttime\t" << ttime;

                    if(util::check_sorted(test_array, array_size))
                        std::cout << "\tpassed" << std::endl;
                    else
                        std::cout << "\tfailed" << std::endl;
                    delete[] test_array;
                    break;
                }
                case 'f':
                {
                    float* test_array = new float[array_size];
                    srand(r_seed);
                    for(int i = 0; i < array_size; i++) {
                        test_array[i] = ((float)rand() / RAND_MAX)*(RANDOM_MAX - RANDOM_MIN) + RANDOM_MIN;
                    }
                    double tstart, tstop, ttime; 
                    tstart = util::dtime();

                    aspas::parallel_sort(test_array, array_size);

                    tstop = util::dtime();
                    ttime = tstop - tstart;
                    std::cerr << thread_num << "\tfloat\t"<<array_size<<"\ttime\t" << ttime;

                    if(util::check_sorted(test_array, array_size))
                        std::cout << "\tpassed" << std::endl;
                    else
                        std::cout << "\tfailed" << std::endl;
                    delete[] test_array;
                    break;
                }
                case 'd':
                {
                    double* test_array = new double[array_size];
                    srand(r_seed);
                    for(int i = 0; i < array_size; i++) {
                        test_array[i] = ((double)rand() / RAND_MAX)*(RANDOM_MAX - RANDOM_MIN) + RANDOM_MIN;
                    }
                    double tstart, tstop, ttime; 
                    tstart = util::dtime();

                    aspas::parallel_sort(test_array, array_size);

                    tstop = util::dtime();
                    ttime = tstop - tstart;
                    std::cerr << thread_num << "\tdouble\t"<<array_size<<"\ttime\t" << ttime;

                    if(util::check_sorted(test_array, array_size))
                        std::cout << "\tpassed" << std::endl;
                    else
                        std::cout << "\tfailed" << std::endl;
                    delete[] test_array;
                    break;
                }
            }
        }
    }
    
    return 0;
}
