#!/bin/bash -

for j in 1 2 3 
do
./testsort.out -t i -s 100000000 
done

# single-threaded version
#for i in 10000 100000 1000000 10000000 100000000
#do
#    for j in 1 2 3 
#    do
#        ./testsort.out -t i -s $i -c -l
#    done                           
#    for j in 1 2 3                 
#    do                             
#        ./testsort.out -t f -s $i -c -l
#    done                           
#    for j in 1 2 3                 
#    do                             
#        ./testsort.out -t d -s $i -c -l
#    done
#done

# multi-threaded version
#for i in 12500000 25000000 50000000 100000000 200000000 400000000
#do
#    for j in 1 2 3
#    do
#        ./testsort.out -t i -s $i -n 60 -c -l
#    done                              
#    for j in 1 2 3                    
#    do                                
#        ./testsort.out -t f -s $i -n 60 -c -l
#    done                              
#    for j in 1 2 3                    
#    do                               
#        ./testsort.out -t d -s $i -n 60 -c -l
#    done
#done

