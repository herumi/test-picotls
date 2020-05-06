#!/usr/bin/env bash
set -e

TIMES=10
EVENTS="task-clock,cycles,instructions,faults,cache-references,cache-misses,L1-dcache-loads,L1-dcache-load-misses,L1-dcache-stores,LLC-loads,LLC-load-misses,LLC-stores"

rm -f *.log

for i in $(seq 1 $TIMES)
do
  sudo perf stat -e $EVENTS ./without-sscanf 16384 2>> without-sscanf.log >/dev/null
done

for i in $(seq 1 $TIMES)
do
  sudo perf stat -e $EVENTS ./with-sscanf 16384 2>> with-sscanf.log >/dev/null
done