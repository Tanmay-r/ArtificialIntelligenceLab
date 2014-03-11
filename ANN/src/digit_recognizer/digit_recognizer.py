import numpy as np

def f_digit_recognizer(inputArr):
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