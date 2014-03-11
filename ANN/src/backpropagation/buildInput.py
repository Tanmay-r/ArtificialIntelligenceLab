import numpy as np

def buildInput(num):
	inputs = []
	for i in range(2**num):
		temp = []
		temp.append(-1)
		k = i
		for j in range(num):
			temp.append(k%2)
			k = k/2
		inputs.append(np.array(temp))
	return np.array(inputs)

def buildInput2(num):
	inputs = []
	temp = [-1,0,1,1,1,1,1,1];
	inputs.append(np.array(temp))
	temp = [-1,0,0,0,1,1,0,0];
	inputs.append(np.array(temp))
	temp = [-1,1,0,1,1,0,1,1];
	inputs.append(np.array(temp))
	temp = [-1,1,0,1,1,1,1,0];
	inputs.append(np.array(temp))
	temp = [-1,1,1,0,1,1,0,0];
	inputs.append(np.array(temp))
	temp = [-1,1,1,1,0,1,1,0];
	inputs.append(np.array(temp))
	temp = [-1,1,1,1,0,1,1,1];
	inputs.append(np.array(temp))
	temp = [-1,0,0,1,1,1,0,0];
	inputs.append(np.array(temp))
	temp = [-1,1,1,1,1,1,1,1];
	inputs.append(np.array(temp))
	temp = [-1,1,1,1,1,1,1,0];
	inputs.append(np.array(temp))
	return np.array(inputs)