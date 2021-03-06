#!/bin/bash
#Credits: Duhan Caraciolo (dcms2)
shopt -s nocasematch
IFS=$(echo -en "\n\b")
 
names=("CF" "Uva" "ICPC" "LA" "URI" "Spoj" "Timus" "NONE" "Seletiva" "Facebook" "GoogleCodeJam")
 
for name in ${names[*]}; do
  mkdir $name
done
 
files=$(ls)
 
for file in $files; do
  if [ -d $file ]; then
    continue;
  fi
  echo "$file"
  for name in ${names[*]}; do
    if [[ "$file" = $name* ]]; then
      mv $file $name
    fi
  done
done
