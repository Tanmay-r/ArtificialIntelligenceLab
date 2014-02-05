import numpy as np
import math
import buildInput
import functions
import sys

def computeError(Y, Ypredicted):
	error = 0
	for i in range(Ypredicted.shape[0]):
		error += (Y[i] - Ypredicted[i])*(Y[i] - Ypredicted[i])
	return error/Ypredicted.shape[0]

def addDeltaW(w, deltaW, layer):
	for l in range(layer.shape[0] - 1):
		for j in range(1, layer[l + 1]):
			for i in range(layer[l]):
				w[l][j - 1][i] += deltaW[l][j - 1][i]
	return w

def computeDeltaW(eta, delta, outputs, x, layer):
	deltaW = initializeW(layer, 1)
	inputV = []
	for l in range(layer.shape[0] - 1):
		if l == 0:
			inputV = x
		else:
			inputV = []
			inputV.append(-1)
			for j in range(1, layer[l]):
				inputV.append(outputs[l - 1][j - 1])
			inputV = np.array(inputV)
		for j in range(1, layer[l + 1]):
			for i in range(layer[l]):
				deltaW[l][j - 1][i] = eta * delta[l][j - 1] * inputV[i]
	return deltaW

def deltaOutermost(layer, t, outputs):
	deltaOutermost = []
	for i in range(layer[layer.shape[0] - 1] - 1):
		oj = outputs[layer.shape[0] - 2][i]
		deltaOutermost.append((t[i] - oj)*oj*(1 - oj))
	return np.array(deltaOutermost)

def modifyDelta(t, w, outputs, layer):
	delta = initializeDelta(layer)
	delta[layer.shape[0] - 2] = deltaOutermost(layer, t, outputs) 
	for l in range(1, layer.shape[0] - 1):
		for j in range(1, layer[l]):
			summation = 0
			oj = outputs[l - 1][j - 1]
			delta[l - 1][j - 1] = oj*(1 - oj)
			for k in range(1, layer[l + 1]):
				summation += w[l][k - 1][j]*delta[l][k - 1]
			delta[l - 1][j - 1] *= summation
	return delta

def sigmoid(net):
	return 1/(1 + math.exp(-net))

def feedForward(w, x, layer):
	outputsNew = initializeDelta(layer)	
	for l in range(layer.shape[0] - 1):
		for j in range(1, layer[l+1]):
			net = np.dot(w[l][j-1].T, x)
			outputsNew[l][j - 1] = sigmoid(net)
		x = []
		x.append(-1)
		for j in range(1, layer[l+1]):
			x.append(outputsNew[l][j-1])
		x = np.array(x)
	return outputsNew

def initializeDelta(layer):
	delta = []
	for l in range(layer.shape[0] - 1):
		layerW = []
		for j in range(1, layer[l + 1]):
			layerW.append(0.0)
		delta.append(np.array(layerW))
	return np.array(delta)

def initializeW(layer, initializationParamter):
	w = []
	for l in range(layer.shape[0] - 1):
		layerW = []
		for j in range(1, layer[l + 1]):
			temp = []
			for i in range(layer[l]):
				temp.append(np.random.uniform(-initializationParamter, initializationParamter))
			layerW.append(np.array(temp))
		w.append(np.array(layerW))
	return np.array(w)

def momentum(eta, M, delta, outputs, x, layer, wprev, w):
	deltaW = initializeW(layer, 1)
	inputV = []
	for l in range(layer.shape[0] - 1):
		if l == 0:
			inputV = x
		else:
			inputV = []
			inputV.append(-1)
			for j in range(1, layer[l]):
				inputV.append(outputs[l - 1][j - 1])
			inputV = np.array(inputV)
		for j in range(1, layer[l + 1]):
			for i in range(layer[l]):
				deltaW[l][j - 1][i] = (1- M)* eta * delta[l][j - 1] * inputV[i] + M*(w[l][j - 1][i] - wprev[l][j - 1][i])
	return deltaW

def backpropagation(layer, X, Y, w, eta, M):
	#layer[layer.shape[0] - 1] += 1

	#w = initializeW(layer, 1)
	#print w
	wprev = w
	delta = initializeDelta(layer)
	outputs = initializeDelta(layer)

	errorThresh = 0.02
	#eta = 0.9
	error = 15
	#M = 0.8
	epoch  = 0
	while error > errorThresh:
		epoch += 1
		#print "Epoch Number :", epoch

		totaldeltaW = initializeW(layer,0)
		for i in range(X.shape[0]):
			x = X[i]

			#modify outputs
			outputs = feedForward(w, x, layer)
			
			#modify delta
			delta = modifyDelta(Y[i], w, outputs, layer)

			#update deltaW
			deltaW = momentum(eta, M, delta, outputs, x, layer, wprev, w)

			#modify w			
			totaldeltaW = addDeltaW(totaldeltaW, deltaW, layer)
			
		wprev = w
		w = addDeltaW(w, totaldeltaW, layer)
		error = 0
		for i in range(X.shape[0]):
			x = X[i]

			#modify outputs
			outputs = feedForward(w, x, layer)

			#update error
			error += computeError(Y[i], outputs[layer.shape[0] - 2])
		error = error/X.shape[0]
	print eta, epoch, error
	#print "w = ", w		

'''
inputArray = buildInput.buildInput(2)
outputArray = functions.f_XOR(inputArray)
layer = np.array([3, 3, 2])
weight = initializeW(layer , 1)
w = weight[:]
backpropagation(layer, inputArray, outputArray, w)
'''

for i in range(1,3):
	if (i==1):
		inputArray = buildInput.buildInput(2)
		outputArray = functions.f_XOR(inputArray)
		layer = np.array([3, 3, 2])
 		w = []
		delta = []
		delta.append(np.array([ 0.43131914,  0.79113672, -0.70760104]))
		delta.append(np.array([-0.91775761, -0.13261828, -0.22987526]))
		w.append(np.array(delta))
		delta = []
		delta.append(np.array([ 0.04983947, -0.71121736, -0.95094728]))
		w.append(np.array(delta))
		print "XOR"
		for j in range(1,11):
			w = []
			delta = []
			delta.append(np.array([ 0.43131914,  0.79113672, -0.70760104]))
			delta.append(np.array([-0.91775761, -0.13261828, -0.22987526]))
			w.append(np.array(delta))
			delta = []
			delta.append(np.array([ 0.04983947, -0.71121736, -0.95094728]))
			w.append(np.array(delta))
			backpropagation(layer, inputArray, outputArray, w, j/10.0, 0.8)
	
	elif (i==2):
		inputArray = buildInput.buildInput(2)
		outputArray = functions.f_OR(inputArray)
		layer = np.array([3, 3, 2])
		w = []
		delta = []
		delta.append(np.array([ 0.43131914,  0.79113672, -0.70760104]))
		delta.append(np.array([-0.91775761, -0.13261828, -0.22987526]))
		w.append(np.array(delta))
		delta = []
		delta.append(np.array([ 0.04983947, -0.71121736, -0.95094728]))
		w.append(np.array(delta))
		print "OR"
		for j in range(1,11):
			w = []
			delta = []
			delta.append(np.array([ 0.43131914,  0.79113672, -0.70760104]))
			delta.append(np.array([-0.91775761, -0.13261828, -0.22987526]))
			w.append(np.array(delta))
			delta = []
			delta.append(np.array([ 0.04983947, -0.71121736, -0.95094728]))
			w.append(np.array(delta))
			backpropagation(layer, inputArray, outputArray, w, j/10.0, 0.8)

	elif (i==3):
		inputArray = buildInput.buildInput(5)
		outputArray = functions.f_Palindrome(inputArray)
		layer = np.array([6, 6, 2])
		w = []
		delta = []
		delta.append(np.array([ 0.55448041, -0.74066232, -0.83553947, -0.51159523, -0.08439398,
         0.21961885]))
		delta.append(np.array([ 0.64789767,  0.70873111,  0.29266862,  0.0552906 , -0.2447614 ,
        -0.32476857]))
        delta.append(np.array([-0.92280647, -0.19910645, -0.77351621, -0.46819215, -0.03387104,
        -0.73321612]))
        delta.append(np.array([-0.52558493,  0.11296398, -0.04232525,  0.76350367,  0.97105836,
        -0.72765551]))
        delta.append(np.array([ 0.99899542, -0.76512089,  0.65978507, -0.39362907, -0.42090216,
         0.84945477]))
        w.append(np.array(delta))
        delta = []
        delta.append(np.array([-0.78645273,  0.98488616, -0.54593629, -0.23048046,  0.87283381, 0.22333159))
        w.append(np.array(delta))

		print "Palindrome"
		for j in range(1,10):
			w = []
			delta = []
			delta.append(np.array([ 0.55448041, -0.74066232, -0.83553947, -0.51159523, -0.08439398,
	         0.21961885]))
			delta.append(np.array([ 0.64789767,  0.70873111,  0.29266862,  0.0552906 , -0.2447614 ,
	        -0.32476857]))
	        delta.append(np.array([-0.92280647, -0.19910645, -0.77351621, -0.46819215, -0.03387104,
	        -0.73321612]))
	        delta.append(np.array([-0.52558493,  0.11296398, -0.04232525,  0.76350367,  0.97105836,
	        -0.72765551]))
	        delta.append(np.array([ 0.99899542, -0.76512089,  0.65978507, -0.39362907, -0.42090216,
	         0.84945477]))
			w.append(np.array(delta))
			delta = []
			delta.append(np.array([-0.78645273,  0.98488616, -0.54593629, -0.23048046,  0.87283381,
	         0.22333159))
			w.append(np.array(delta))
			backpropagation(layer, inputArray, outputArray, w, j/10.0, 0.8)

	elif (i==4):
		inputArray = buildInput.buildInput(5)
		outputArray = functions.f_IsMajority(inputArray)
		layer = np.array([6, 6, 2])
		w = []
		delta = []
		delta.append(np.array([ 0.55448041, -0.74066232, -0.83553947, -0.51159523, -0.08439398,
         0.21961885]))
		delta.append(np.array([ 0.64789767,  0.70873111,  0.29266862,  0.0552906 , -0.2447614 ,
        -0.32476857]))
        delta.append(np.array([-0.92280647, -0.19910645, -0.77351621, -0.46819215, -0.03387104,
        -0.73321612]))
        delta.append(np.array([-0.52558493,  0.11296398, -0.04232525,  0.76350367,  0.97105836,
        -0.72765551]))
        delta.append(np.array([ 0.99899542, -0.76512089,  0.65978507, -0.39362907, -0.42090216,
         0.84945477]))
		w.append(np.array(delta))
		delta = []
		delta.append(np.array([-0.78645273,  0.98488616, -0.54593629, -0.23048046,  0.87283381,
         0.22333159))
		w.append(np.array(delta))
		print "IsMajority"
		for j in range(1,10):
			w = []
			delta = []
			delta.append(np.array([ 0.55448041, -0.74066232, -0.83553947, -0.51159523, -0.08439398,
	         0.21961885]))
			delta.append(np.array([ 0.64789767,  0.70873111,  0.29266862,  0.0552906 , -0.2447614 ,
	        -0.32476857]))
			delta.append(np.array([-0.92280647, -0.19910645, -0.77351621, -0.46819215, -0.03387104,
	        -0.73321612]))
			delta.append(np.array([-0.52558493,  0.11296398, -0.04232525,  0.76350367,  0.97105836,
	        -0.72765551]))
	        delta.append(np.array([ 0.99899542, -0.76512089,  0.65978507, -0.39362907, -0.42090216,
	         0.84945477]))
			w.append(np.array(delta))
			delta = []
			delta.append(np.array([-0.78645273,  0.98488616, -0.54593629, -0.23048046,  0.87283381,
	         0.22333159))
			w.append(np.array(delta))
			backpropagation(layer, inputArray, outputArray, w, j/10.0, 0.8)
'''
for i in range(1,5):
	if (i==1):
		inputArray = buildInput.buildInput(2)
		outputArray = functions.f_XOR(inputArray)
		layer = np.array([3, 3, 2])
		wt = backpropagationv3.initializeW(layer, 1)
		M = 0.8
		for j in range(1,11):
			w = wt
			backpropagationv3.backpropagation(layer, inputArray, outputArray, w ,j/10.0 , M)
			print "!!!"
		print "*****************"

	elif (i==2):
		inputArray = buildInput.buildInput(2)
		outputArray = functions.f_OR(inputArray)
		layer = np.array([3, 3, 2])
		wt = backpropagationv3.initializeW(layer, 1)
		M = 0.8
		for j in range(1,11):
			w = wt
			backpropagationv3.backpropagation(layer, inputArray, outputArray, w ,j/10.0 , M)
		print "*****************"

	elif (i==3):
		inputArray = buildInput.buildInput(5)
		outputArray = functions.f_Palindrome(inputArray)
		layer = np.array([6, 6, 1])
		wt = backpropagationv3.initializeW(layer, 2)
		M = 0.8
		for j in range(1,11):
			w = wt
			backpropagationv3.backpropagation(layer, inputArray, outputArray, w ,j/10.0 , M)
		print "*****************"

	elif (i==4):
		inputArray = buildInput.buildInput(5)
		outputArray = functions.f_IsMajority(inputArray)
		layer = np.array([6, 6, 1])
		wt = backpropagationv3.initializeW(layer, 1)
		M = 0.8
		for j in range(1,11):
			w = wt
			backpropagationv3.backpropagation(layer, inputArray, outputArray, w ,j/10.0 , M)
'''
