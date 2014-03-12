import numpy as np

def generateTrainingData(file1, file2, file3):
	Y = []
	X = []

	f = open(file1, 'r')
	data = f.read()
	f.close()

	for line in data.split('\n'):
		temp = []
		temp.append(-1)
		line = line.split(',')
		for value in range(4):
			temp.append(float(line[value]))
		X.append(np.array(temp))
		Y.append(np.array([1, 0, 0]))

	f = open(file2, 'r')
	data = f.read()
	f.close()

	for line in data.split('\n'):
		temp = []
		temp.append(-1)
		line = line.split(',')
		for value in range(4):
			temp.append(float(line[value]))
		X.append(np.array(temp))
		Y.append(np.array([0, 1, 0]))

	f = open(file3, 'r')
	data = f.read()
	f.close()

	for line in data.split('\n'):
		temp = []
		temp.append(-1)
		line = line.split(',')
		for value in range(4):
			temp.append(float(line[value]))
		X.append(np.array(temp))
		Y.append(np.array([0, 0, 1]))

	return [np.array(X), np.array(Y)]
