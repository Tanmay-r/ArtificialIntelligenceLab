import backpropagationv3
import numpy as np
import math
import buildInput
import functions

M = 0.8
for i in range(2,3):
	if(i==1):
		inputArray = buildInput.buildInput(2)
		outputArray = functions.f_XOR(inputArray)
		layer = np.array([3, 3, 2])
		wt = backpropagationv3.initializeW(layer, 0)
		print "XOR"
		for j in range(1,2):
			tempwt = backpropagationv3.initializeW(layer, j)
			w = backpropagationv3.addDeltaW(tempwt, wt , layer)
			backpropagationv3.backpropagation(layer, inputArray, outputArray, w ,0.1 , M)
		print "*****************"
	elif(i==2):
		inputArray = buildInput.buildInput(3)
		outputArray = functions.f_Palindrome(inputArray)
		layer = np.array([4, 4, 2])
		wt = backpropagationv3.initializeW(layer, 0)
		print "Palindrome"
		for j in range(1,4):
			tempwt = backpropagationv3.initializeW(layer, j)
			w = backpropagationv3.addDeltaW(tempwt, wt , layer)
			backpropagationv3.backpropagation(layer, inputArray, outputArray, w ,0.5+j/10.0, M)
		print "*****************"
	elif(i==3):
		inputArray = buildInput.buildInput(5)
		outputArray = functions.f_IsMajority(inputArray)
		layer = np.array([6, 6, 2])
		wt = backpropagationv3.initializeW(layer, 0)
		print "Majority"
		for j in range(1,4):
			tempwt = backpropagationv3.initializeW(layer, j)
			w = backpropagationv3.addDeltaW(tempwt, wt , layer)
			backpropagationv3.backpropagation(layer, inputArray, outputArray, w ,0.5+j/10.0 , M)
		print "*****************"