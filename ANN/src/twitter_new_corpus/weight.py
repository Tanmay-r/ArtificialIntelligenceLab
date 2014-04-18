from ..backpropagation.backpropagation import *

def store_weight(w, layer):

	f = open('weights2', 'w')
	for l in range(layer.shape[0] - 1):
		for j in range(1, layer[l + 1]):
			for i in range(layer[l]):
				f.write(str(w[l][j - 1][i]) + ' ')
	f.close()

def load_weight(file_name, w, layer):

	f = open(file_name, 'r')
	data = f.read()
	f.close()

	weights = data.split(' ')
	m = 0
	for l in range(layer.shape[0] - 1):
		for j in range(1, layer[l + 1]):
			for i in range(layer[l]):
				w[l][j - 1][i] = float(weights[m])
				m += 1

def storeWordList(wordList):
	f = open('wordList', 'w')
	for w in wordList:
		f.write(w + ' ')
	f.close()

def loadWordList(file_name):
	f = open(file_name, 'r')
	data = f.read()
	f.close()

	wordList = data.split(' ')
	return np.array(wordList)