import numpy as np

def f_NAND(inputArr):
	output = []
	for i in range(inputArr.shape[0]):
		res = inputArr[i][1]
		temp = []
		for j in range(2, inputArr[i].shape[0]):
			res = not(bool(res) and bool(inputArr[i][j]))
		temp.append(int(res))
		output.append(np.array(temp))
	return np.array(output)