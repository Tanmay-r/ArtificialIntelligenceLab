from ..backpropagation.backpropagation import *
from ..backpropagation.buildInput import *
from ..twitter.generateTrainingData import *
from ..twitter.getWordList import *
import numpy as np
import math

M = 0.8
eta = 0.9
errorThresh = 10

wordList = getWordList("/home/tanmay/Downloads/GitHub/ArtificialIntelligenceLab/ANN/data/twitter/twitter_positive",
	"/home/tanmay/Downloads/GitHub/ArtificialIntelligenceLab/ANN/data/twitter/twitter_negative",
	"/home/tanmay/Downloads/GitHub/ArtificialIntelligenceLab/ANN/data/twitter/twitter_objective", 3)
[X, Y] = generateTrainingData("/home/tanmay/Downloads/GitHub/ArtificialIntelligenceLab/ANN/data/twitter/dataset1/train/twitter_positive",
	"/home/tanmay/Downloads/GitHub/ArtificialIntelligenceLab/ANN/data/twitter/twitter_objective",
	"/home/tanmay/Downloads/GitHub/ArtificialIntelligenceLab/ANN/data/twitter/dataset1/train/twitter_negative", 
	wordList, 3)
layer = np.array([X[0].shape[0], 2])

w = initializeW(layer, 1)
print "Estimating weights..."
backpropagation(layer, X, Y, w, eta, M, errorThresh)

wordList = getWordList("/home/tanmay/Downloads/GitHub/ArtificialIntelligenceLab/ANN/data/twitter/twitter_positive",
	"/home/tanmay/Downloads/GitHub/ArtificialIntelligenceLab/ANN/data/twitter/twitter_objective",
	"", 2)
[X, Y] = generateTrainingData("/home/tanmay/Downloads/GitHub/ArtificialIntelligenceLab/ANN/data/twitter/dataset1/train/twitter_positive",
	"/home/tanmay/Downloads/GitHub/ArtificialIntelligenceLab/ANN/data/twitter/dataset1/train/twitter_negative", 
	"",
	wordList, 2)
layer = np.array([X[0].shape[0], 2])

wnew = initializeW(layer, 1)
backpropagation(layer, X, Y, wnew, eta, M, errorThresh)

total = 0
correct = 0

#negative
f = open("/home/tanmay/Downloads/GitHub/ArtificialIntelligenceLab/ANN/data/twitter/dataset1/test/twitter_negative", 'r')
data = f.read()
f.close()

for line in data.split('\n'):
	total = total + 1
	temp = []
	temp.append(-1)
	words = getWords(line)
	for w in wordList:
		if w in words:
			temp.append(1)
		else:
			temp.append(0)
	X = np.array(temp)
	outputs = feedForward(w, X, layer)
	if(outputs[outputs.shape[0] - 1][j] < 0.5):
		correct = correct + 1

#positive
f = open("/home/tanmay/Downloads/GitHub/ArtificialIntelligenceLab/ANN/data/twitter/dataset1/test/twitter_positive", 'r')
data = f.read()
f.close()

for line in data.split('\n'):
	total = total + 1
	temp = []
	temp.append(-1)
	words = getWords(line)
	for w in wordList:
		if w in words:
			temp.append(1)
		else:
			temp.append(0)
	X = np.array(temp)
	outputs = feedForward(w, X, layer)
	if(outputs[outputs.shape[0] - 1][j] > 0.5):
		outputs = feedForward(wnew, X, layer)
		if(outputs[outputs.shape[0] - 1][j] > 0.5):
			correct = correct + 1

#objective
f = open("/home/tanmay/Downloads/GitHub/ArtificialIntelligenceLab/ANN/data/twitter/dataset1/test/twitter_objective", 'r')
data = f.read()
f.close()

for line in data.split('\n'):
	total = total + 1
	temp = []
	temp.append(-1)
	words = getWords(line)
	for w in wordList:
		if w in words:
			temp.append(1)
		else:
			temp.append(0)
	X = np.array(temp)
	outputs = feedForward(w, X, layer)
	if(outputs[outputs.shape[0] - 1][j] > 0.5):
		outputs = feedForward(wnew, X, layer)
		if(outputs[outputs.shape[0] - 1][j] < 0.5):
			correct = correct + 1

print correct, " ", total, correct/(total * 1.0)