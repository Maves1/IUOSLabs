#!/bin/bash

if [ ! -f num.txt ]; then
  echo 0 > num.txt;
fi

if [ -f num.lock ]; then
  exit
fi

ln num.txt num.lock

counter=0
while [[ "$counter" -lt 100 ]]; do
  i=$(tail -1 num.txt)
  counter=$((counter + 1))
  echo "$counter" >> num.txt;
  sleep 1
done

rm num.lock
