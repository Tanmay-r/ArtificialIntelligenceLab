import numpy as np

def f_Parity(inputArr):
	output = []
	for i in range(inputArr.shape[0]):
		res = 0
		temp = []
		length = inputArr[i].shape[0]
		for j in range(1, length):
			if(inputArr[i][j]==1):
				res = res + 1
		if(res % 2 == 0):
			temp.append(1)
		else:
			temp.append(0)
		output.append(np.array(temp))
	return np.array(output)
