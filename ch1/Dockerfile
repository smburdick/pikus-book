FROM ubuntu:18.04

WORKDIR /usr/src/app

RUN apt-get update

RUN apt-get install -y google-perftools

RUN apt-get install clang -y

COPY 01_substring_sort_a.c .
COPY 01.h .
COPY 01_substring_sort.c .
RUN  apt-get --reinstall install findutils

RUN clang++ -g -mavx2 -Wall -pedantic 01_substring_sort.c 01_substring_sort_a.c -o a.out
CMD ["./a.out"]
