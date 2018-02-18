CXX = icpc
CXXFLAGS = -Iinclude -std=c++11 -c -Wall -Wextra -O3 #-g
LDFLAGS = -std=c++11 -pthread

TARGET = 
ifdef ISA
ifeq ($(ISA),mic)
	TARGET = -mmic
else
ifeq ($(ISA),avx)
	TARGET = -xavx
else
ifeq ($(ISA),avx2)
	TARGET = -xCORE-AVX2
else
	TARGET = -xavx
endif # avx2
endif # avx
endif # mic
else
	TARGET = -xavx
endif # empty

CXXFLAGS += $(TARGET) 
LDFLAGS  += $(TARGET) 
#CXXFLAGS += -mmic
#LDFLAGS  += -mmic
#CXXFLAGS += -xavx
#LDFLAGS  += -xavx
#CXXFLAGS += -xCORE-AVX2
#LDFLAGS  += -xCORE-AVX2
ASPAS_HEADS = include/aspas.h include/aspas.tcc \
			  include/aspas_merge_avx.tcc \
			  include/aspas_merge_mic.tcc \
			  include/merger.h \
			  include/merger.tcc \
			  include/sorter.h \
              include/sorter_avx.tcc \
			  include/sorter_mic.tcc 
OBJS = testsort.o

all: testsort.out

testsort.o: src/testsort.cpp $(ASPAS_HEADS)
	$(CXX) $(CXXFLAGS) $<

testsort.out: $(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $^

clean:
	-rm -rf *.o *.out

