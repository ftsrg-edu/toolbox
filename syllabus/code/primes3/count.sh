#!/bin/bash

echo 1 és n közötti prímszámok számának meghatározása.
for i in 10 100 1000
do
	echo $i: 
	primes $i
done
