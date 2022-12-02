clang++-11 -g -mavx2 -Wall -pedantic main.c compare.c -lprofiler -o a.out
CPUPROFILE=prof.data ./a.out
google-pprof --text ./a.out prof.data
