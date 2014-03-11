import getWordList
import numpy as np
import getWords
import backpropagationv3

def generateTrainingData(file1, file2, file3):
	wordList = getWordList.getWordList()

	Y = []
	X = []

	f = open(file1, 'r')
	data = f.read()
	f.close()

	for line in data.split('\n'):
		temp = []
		words = getWords.getWords(line)
		for w in wordList:
			if w in words:
				temp.append(1)
			else:
				temp.append(0)
		X.append(np.array(temp))
		Y.append(np.array([0, 0 , 1]))

	f = open(file2, 'r')
	data = f.read()
	f.close()

	for line in data.split('\n'):
		temp = []
		words = getWords.getWords(line)
		for w in wordList:
			if w in words:
				temp.append(1)
			else:
				temp.append(0)
		X.append(np.array(temp))
		Y.append(np.array([0, 1, 0]))
	
	f = open(file3, 'r')
	data = f.read()
	f.close()

	for line in data.split('\n'):
		temp = []
		words = getWords.getWords(line)
		for w in wordList:
			if w in words:
				temp.append(1)
			else:
				temp.append(0)
		X.append(np.array(temp))
		Y.append(np.array([1, 0, 0]))

	return [np.array(X), np.array(Y)]

[X, Y] = generateTrainingData("data/twitter_negative", "data/twitter_positive", "data/twitter_objective")
layer = np.array([X[0].shape[0], 4])
print layer
w = backpropagationv3.initializeW(layer, 1)
finalW = backpropagationv3.backpropagation(layer, X, Y, w, 0.9, 0.8)
percentage =0
total = 0
[X, Y] = generateTrainingData("data/twitter_negative_test","data/twitter_positive_test" , "data/twitter_objective_test")
for i in range(Y.shape[0]):
	outputs = backpropagationv3.feedForward(finalW, X[i], layer)
	print Y[i], "   ", outputs[i]
	#for j in range(Y[i].shape[0]):
	#	total = total+1
	#	print Y
		#if((Y[i][j] == 0 and outputs[outputs.shape[0] - 1][j] < 0.5) or (Y[i][j] == 1 and outputs[outputs.shape[0] - 1][j] > 0.5)):
		#	percentage = percentage + 1
		#print "Actual output = ", Y[i][j], " ", "Function output = ", outputs[outputs.shape[0] - 1][j]

#print percentage,"  ", total,"  ", percentage/(total*1.0)