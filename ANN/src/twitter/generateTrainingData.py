import numpy as np
from ..twitter.getWords import *

def generateTrainingData(file1, file2, file3, wordList, param):
	Y = []
	X = []

	f = open(file1, 'r')
	data = f.read()
	f.close()

	for line in data.split('\n'):
		temp = []
		temp.append(-1)
		words = getWords(line)
		for w in wordList:
			if w in words:
				temp.append(1)
			else:
				temp.append(0)
		X.append(np.array(temp))
		Y.append(np.array([1]))

	f = open(file2, 'r')
	data = f.read()
	f.close()

	for line in data.split('\n'):
		temp = []
		temp.append(-1)
		words = getWords(line)
		for w in wordList:
			if w in words:
				temp.append(1)
			else:
				temp.append(0)
		X.append(np.array(temp))
		if(param == 3):
			Y.append(np.array([1]))
		else:
			Y.append(np.array([0]))

	if(param == 3):
		f = open(file3, 'r')
		data = f.read()
		f.close()

		for line in data.split('\n'):
			temp = []
			temp.append(-1)
			words = getWords(line)
			for w in wordList:
				if w in words:
					temp.append(1)
				else:
					temp.append(0)
			X.append(np.array(temp))
			Y.append(np.array([0]))
	return [np.array(X), np.array(Y)]
