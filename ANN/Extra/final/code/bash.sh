#!/bin/bash
rm -r output
mkdir -p output
Func[1]='Parity'
Func[2]='XOR'
Func[3]='OR'
Func[4]='Palindrome'
Func[5]='Majority'
for i in {1..5}
do
	echo $i
	python backpropagationv3.py $i > output/${Func[$i]}
	echo $i
done
