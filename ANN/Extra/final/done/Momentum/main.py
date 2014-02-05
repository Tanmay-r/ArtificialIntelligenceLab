import backpropagationv3
import numpy as np
import math
import buildInput
import functions

for i in range(1,2):
	if(i==1):
		inputArray = buildInput.buildInput(2)
		outputArray = functions.f_XOR(inputArray)
		layer = np.array([3, 3, 2])
		wt = backpropagationv3.initializeW(layer, 0)
		print "XOR"
		for j in range(7,11):
			tempwt = backpropagationv3.initializeW(layer, j)
			w = backpropagationv3.addDeltaW(tempwt, wt , layer)
			backpropagationv3.backpropagation(layer, inputArray, outputArray, w ,0.9 , j/10.0)
		print "*****************"
	elif(i==2):
		inputArray = buildInput.buildInput(2)
		outputArray = functions.f_Palindrome(inputArray)
		layer = np.array([3, 3, 2])
		wt = backpropagationv3.initializeW(layer, 0)
		print "Palindrome"
		for j in range(1,11):
			tempwt = backpropagationv3.initializeW(layer, j)
			w = backpropagationv3.addDeltaW(tempwt, wt , layer)
			backpropagationv3.backpropagation(layer, inputArray, outputArray, w ,0.9 , j/10.0)
		print "*****************"
	elif(i==3):
		inputArray = buildInput.buildInput(5)
		outputArray = functions.f_IsMajority(inputArray)
		layer = np.array([6, 6, 2])
		wt = backpropagationv3.initializeW(layer, 0)
		print "Majority"
		for j in range(10,11):
			tempwt = backpropagationv3.initializeW(layer, j)
			w = backpropagationv3.addDeltaW(tempwt, wt , layer)
			backpropagationv3.backpropagation(layer, inputArray, outputArray, w ,0.9 , j/10.0)
		print "*****************"