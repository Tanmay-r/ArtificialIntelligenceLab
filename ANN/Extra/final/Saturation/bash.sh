#!/bin/bash
rm -r output
mkdir -p output
Func[2]='XOR'
Func[3]='OR'
Func[4]='Palindrome'
Func[5]='Majority'
for i in {1..4}
do
	echo $i
	rm -r output/${Func[$i]}
	mkdir -p output/${Func[$i]}
	for j in 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1
	do
		echo $j
		python backpropagationv3.py $i $j > output/${Func[$i]}/$j
	done
	echo $i
done
