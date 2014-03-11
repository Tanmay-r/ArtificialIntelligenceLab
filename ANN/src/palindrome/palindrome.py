import numpy as np

def f_Palindrome(inputArr):
	output = []
	for i in range(inputArr.shape[0]):
		res = 1
		temp = []
		length = inputArr[i].shape[0]
		for j in range(1, length/2):
			if(inputArr[i][j]!=inputArr[i][length-j]):
				res = 0
				break
		temp.append(res)
		output.append(np.array(temp))
	return np.array(output)