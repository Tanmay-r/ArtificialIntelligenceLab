from ..backpropagation.backpropagation import *
from ..backpropagation.buildInput import *
from ..iris.generateTrainingData import *
import numpy as np
import math

M = 0.5
eta = 0.01
errorThresh = 10

[inputArray, outputArray] = generateTrainingData("/home/tanmay/Downloads/GitHub/ArtificialIntelligenceLab/ANN/data/iris/dataset1/train/Iris-setosa"
	,"/home/tanmay/Downloads/GitHub/ArtificialIntelligenceLab/ANN/data/iris/dataset1/train/Iris-versicolor"
	,"/home/tanmay/Downloads/GitHub/ArtificialIntelligenceLab/ANN/data/iris/dataset1/train/Iris-virginica")
layer = np.array([5, 5, 4])

print inputArray

print outputArray

w = initializeW(layer, 1)
print "Estimating weights..."
backpropagation(layer, inputArray, outputArray, w, eta, M, errorThresh)
print "Weights: "
print w

[testInput, testOuput] = generateTrainingData("/home/tanmay/Downloads/GitHub/ArtificialIntelligenceLab/ANN/data/iris/dataset1/test/Iris-setosa"
	,"/home/tanmay/Downloads/GitHub/ArtificialIntelligenceLab/ANN/data/iris/dataset1/test/Iris-versicolor"
	,"/home/tanmay/Downloads/GitHub/ArtificialIntelligenceLab/ANN/data/iris/dataset1/test/Iris-virginica")


#while(1):
total = 0
correct = 0
for i in range(testInput.shape[0]):
	total = total + 1
	X = testInput[i]
	actualY = testOuput[i]
	outputs = feedForward(w, X, layer)
	predicted = []
	Y = outputs[1]
	for j in range(Y.shape[0]):
		if(Y[j] < 0.5):
			predicted.append(0)
		else:
			predicted.append(1)

	predicted = np.array(predicted)
	flag = 1
	print "outputs = ", predicted, " actualY = ", actualY
	for j in range(predicted.shape[0]):
		if(predicted[j] != actualY[j]):
			flag = 0

	if(flag == 1):
		correct = correct + 1
	'''
	Y = Y[::-1]
	total = total + 1
	if(computeError(Y, np.array([1,0,0])) < et) :
		if(actualY[0] == 1):
			correct = correct + 1
	elif(computeError(Y, np.array([0,1,0])) < et):
		if(actualY[1] == 1):
			correct = correct + 1
	elif(computeError(Y, np.array([0,0,1])) < et):
		if(actualY[2] == 1):
			correct = correct + 1
	'''
print correct, " ", total, " ", correct/(total*1.0)