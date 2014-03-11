from ..backpropagation.backpropagation import *
from ..backpropagation.buildInput import *
from ..digit_recognizer.digit_recognizer import *
import numpy as np
import math

M = 0.8
eta = 0.9
errorThresh = 0.2

inputArray = buildInput(7)
outputArray = f_digit_recognizer(inputArray)
layer = np.array([8, 7, 5])

w = initializeW(layer, 1)
print "Estimating weights..."
backpropagation(layer, inputArray, outputArray, w, eta, M, errorThresh)
print "Weights: "
print w

flag = 'Y'
while(flag == 'Y'):
	x = []
	x.append(-1)
	x.append(input('Please enter the value of A[1]: '))
	x.append(input('Please enter the value of A[2]: '))
	x.append(input('Please enter the value of A[3]: '))
	x.append(input('Please enter the value of A[4]: '))
	x.append(input('Please enter the value of A[5]: '))
	x.append(input('Please enter the value of A[6]: '))
	x.append(input('Please enter the value of A[7]: '))
	inputX = np.array(x)
	outputs = feedForward(w, inputX, layer)
	Y = outputs[1]
	Y = Y[::-1]

	et = 0.05
	if(computeError(Y, np.array([0,0,0,0])) < et):
		print "Digit(A) = ", 0
	if(computeError(Y, np.array([0,0,0,1])) < et):
		print "Digit(A) = ", 1
	if(computeError(Y, np.array([0,0,1,0])) < et):
		print "Digit(A) = ", 2
	if(computeError(Y, np.array([0,0,1,1])) < et):
		print "Digit(A) = ", 3
	if(computeError(Y, np.array([0,1,0,0])) < et):
		print "Digit(A) = ", 4
	if(computeError(Y, np.array([0,1,0,1])) < et):
		print "Digit(A) = ", 5
	if(computeError(Y, np.array([0,1,1,0])) < et):
		print "Digit(A) = ", 6
	if(computeError(Y, np.array([0,1,1,1])) < et):
		print "Digit(A) = ", 7
	if(computeError(Y, np.array([1,0,0,0])) < et):
		print "Digit(A) = ", 8
	if(computeError(Y, np.array([1,0,0,1])) < et):
		print "Digit(A) = ", 9
	flag = raw_input('Want to check another? (Y/N) : ')