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

def f_XOR(inputArr):
	output = []
	for i in range(inputArr.shape[0]):
		res = inputArr[i][1]
		temp = []
		for j in range(2, inputArr[i].shape[0]):
			res = bool(res) ^ bool(inputArr[i][j])
		temp.append(int(res))
		output.append(np.array(temp))
	return np.array(output)

def f_OR(inputArr):
	output = []
	for i in range(inputArr.shape[0]):
		res = inputArr[i][1]
		temp = []
		for j in range(2, inputArr[i].shape[0]):
			res = bool(res) or bool(inputArr[i][j])
		temp.append(int(res))
		output.append(np.array(temp))
	return np.array(output)

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

def f_IsMajority(inputArr):
	output = []
	for i in range(inputArr.shape[0]):
		res = 0
		temp = []
		length = inputArr[i].shape[0]
		for j in range(1, length):
			if(inputArr[i][j]==1):
				res = res + 1
			else:
				res = res - 1
		if(res > 0):
			temp.append(1)
		else:
			temp.append(0)
		output.append(np.array(temp))
	return np.array(output)

def f_SevenSegment(inputArr):
	output = []
	for i in range(inputArr.shape[0]):
		res = [0]*4
		if(inputArr[i][1]==0 and 
			inputArr[i][2]==1 and 
			inputArr[i][3]==1 and 
			inputArr[i][4]==1 and 
			inputArr[i][5]==1 and 
			inputArr[i][6]==1 and 
			inputArr[i][7]==1):
			res[0] = 0
			res[1] = 0
			res[2] = 0
			res[3] = 0
		elif(inputArr[i][1]==0 and 
			inputArr[i][2]==0 and 
			inputArr[i][3]==0 and 
			inputArr[i][4]==1 and 
			inputArr[i][5]==1 and 
			inputArr[i][6]==0 and 
			inputArr[i][7]==0):
			res[0] = 1
			res[1] = 0
			res[2] = 0
			res[3] = 0
		elif(inputArr[i][1]==1 and 
			inputArr[i][2]==0 and 
			inputArr[i][3]==1 and 
			inputArr[i][4]==1 and 
			inputArr[i][5]==0 and 
			inputArr[i][6]==1 and 
			inputArr[i][7]==1):
			res[0] = 0
			res[1] = 1
			res[2] = 0
			res[3] = 0
		elif(inputArr[i][1]==1 and 
			inputArr[i][2]==0 and 
			inputArr[i][3]==1 and 
			inputArr[i][4]==1 and 
			inputArr[i][5]==1 and 
			inputArr[i][6]==1 and 
			inputArr[i][7]==0):
			res[0] = 1
			res[1] = 1
			res[2] = 0
			res[3] = 0
		elif(inputArr[i][1]==1 and 
			inputArr[i][2]==1 and 
			inputArr[i][3]==0 and 
			inputArr[i][4]==1 and 
			inputArr[i][5]==1 and 
			inputArr[i][6]==0 and 
			inputArr[i][7]==0):
			res[0] = 0
			res[1] = 0
			res[2] = 1
			res[3] = 0
		elif(inputArr[i][1]==1 and 
			inputArr[i][2]==1 and 
			inputArr[i][3]==1 and 
			inputArr[i][4]==0 and 
			inputArr[i][5]==1 and 
			inputArr[i][6]==1 and 
			inputArr[i][7]==0):
			res[0] = 1
			res[1] = 0
			res[2] = 1
			res[3] = 0
		elif(inputArr[i][1]==1 and 
			inputArr[i][2]==1 and 
			inputArr[i][3]==1 and 
			inputArr[i][4]==0 and 
			inputArr[i][5]==1 and 
			inputArr[i][6]==1 and 
			inputArr[i][7]==1):
			res[0] = 0
			res[1] = 1
			res[2] = 1
			res[3] = 0
		elif(inputArr[i][1]==0 and 
			inputArr[i][2]==0 and 
			inputArr[i][3]==1 and 
			inputArr[i][4]==1 and 
			inputArr[i][5]==1 and 
			inputArr[i][6]==0 and 
			inputArr[i][7]==0):
			res[0] = 1
			res[1] = 1
			res[2] = 1
			res[3] = 0
		elif(inputArr[i][1]==1 and 
			inputArr[i][2]==1 and 
			inputArr[i][3]==1 and 
			inputArr[i][4]==1 and 
			inputArr[i][5]==1 and 
			inputArr[i][6]==1 and 
			inputArr[i][7]==1):
			res[0] = 0
			res[1] = 0
			res[2] = 0
			res[3] = 1
		elif(inputArr[i][1]==1 and 
			inputArr[i][2]==1 and 
			inputArr[i][3]==1 and 
			inputArr[i][4]==1 and 
			inputArr[i][5]==1 and 
			inputArr[i][6]==1 and 
			inputArr[i][7]==0):
			res[0] = 1
			res[1] = 0
			res[2] = 0
			res[3] = 1
		else:
			res[0] = 1
			res[1] = 1
			res[2] = 1
			res[3] = 1
		output.append(np.array(res))
		
	return np.array(output)