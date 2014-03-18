import numpy as np

def generateTrainingData(file):
	Y = []
	X = []

	f = open(file, 'r')
	data = f.read()
	f.close()

	for line in data.split('\n'):
		temp = []
		temp.append(-1)
		line = line.split(' ')

		Y.append(np.array([int(line[1])]))

		for value in range(2, 8):
			temp.append(int(line[value]))
		X.append(np.array(temp))

	return [np.array(X), np.array(Y)]