from ..backpropagation.backpropagation import *
from ..backpropagation.buildInput import *
from ..majority.majority import *
import numpy as np
import math

M = 0.1
eta = 0.9
errorThresh = 0.2

inputArray = buildInput(5)
outputArray = f_Majority(inputArray)
layer = np.array([6, 6, 2])

w = initializeW(layer, 1)
print "Estimating weights..."
backpropagation(layer, inputArray, outputArray, w, eta, M, errorThresh)
print "Weights: "
print w

flag = 'Y'
while(flag == 'Y'):
	x = []
	x.append(-1)
	x.append(input('Please enter the value of A[0]: '))
	x.append(input('Please enter the value of A[1]: '))
	x.append(input('Please enter the value of A[2]: '))
	x.append(input('Please enter the value of A[3]: '))
	x.append(input('Please enter the value of A[4]: '))
	inputX = np.array(x)
	outputs = feedForward(w, inputX, layer)
	if(outputs[layer[layer.shape[0] - 1] - 1] < 0.5):
		print "Majority(A) = ", 0
	else:
		print "Majority(A) = ", 1
	flag = raw_input('Want to check another? (Y/N) : ')