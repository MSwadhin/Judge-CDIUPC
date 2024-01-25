#!/usr/bin/env bash


input="./lst_numbers.txt"
echo $input;
while IFS= read -r line
do
	inpfile="data/inputs/input"$line".txt"
	outfile="data/outputs/output"$line".txt"
	echo $inpfile;
	./validator < $inpfile;
	
done < "$input"
