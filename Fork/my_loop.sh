#!/bin/bash

rm -rf x
for i in `seq 1 1000`;
   do
 	./ex1 >> x
   done 
