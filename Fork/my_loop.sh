#!/bin/bash

rm -rf x
for i in `seq 1 1000`;
   do
 	./ex1 >> x
   done 

old_line=""
find_str="Pai"
num_invertions=0
line_number=1

while read -r line; do
        if [ "$find_str" == "$line" ] && [ "$line" == "$old_line" ]; then
                echo "Inversão na linha: " $line_number 
                num_invertions=$(($num_invertions+1))
        fi
        old_line=$line
        line_number=$(($line_number+1))
done < x

echo "Número de inversões:" $num_invertions " em 1000 execuções!"
