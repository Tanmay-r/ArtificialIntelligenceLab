import numpy as np
import math

def computeError(Y, Ypredicted):
	error = 0
	print Ypredicted
	for i in range(Ypredicted.shape[0]):
		error += 0.5*(Y[i] - Ypredicted[i])*(Y[i] - Ypredicted[i])
	return error

def sigmoid(net):
	return 1/(1 + math.exp(-net))

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

def initializeDelta(layer):
	delta = []
	for l in range(1, layer.shape[0]):
		layerW = []
		for j in range(1, layer[l]):
			layerW.append(0)
		delta.append(np.array(layerW))
	return np.array(delta)

def feedForward(w, x, layer):
	outputsNew = initializeDelta(layer)	
	for l in range(layer.shape[0] - 1):
		layerW = w[l]
		for j in range(1, layerW.shape[0]):
			net = np.dot(layerW[j - 1].T, x)
			outputsNew[l][j - 1] = sigmoid(net)
		x = []
		x.append(-1)
		for j in range(1, layerW.shape[0]):
			x.append(outputsNew[l][j-1])
	print outputsNew
	return outputsNew


def deltaOutermost(layer, t, outputs):
	deltaOutermost = []
	print layer.shape[0] - 1
	for i in range(layer[layer.shape[0] - 1]):
		oj = outputs[layer.shape[0] - 2][i]
		deltaOutermost.append((t[i] - oj)*oj*(1 - oj))
	return np.array(deltaOutermost)

def modifyDelta(t, w, outputs, layer):
	delta = initializeDelta(layer)
	delta[layer.shape[0] - 1] = deltaOutermost(layer, t, outputs) 
	for l in range(layer.shape[0] - 1):
		for j in range(1, layer[l]):
			summation = 0
			oj = outputs[l][j - 1]
			delta[l][j - 1] = oj*(1 - oj)
			for k in range(1, layer[l + 1]):
				summation += w[l][k][j]*delta[l+1][k - 1]
			delta[l][j - 1] *= summation
	return delta

def computeDeltaW(eta, delta, outputs, x):
	deltaW = initializeW()
	inputV = []
	for l in range(layer.shape[0] - 1):
		if l == 0:
			inputV = x
		else:
			inputV = []
			inputV.append(-1)
			for j in range(1, layerW.shape[0]):
				inputV.append(outputs[l - 1][j-1])
		for j in range(1, layer[l + 1]):
			for i in range(layer[l]):
				deltaW[l][j - 1][i] = eta * delta[l][j - 1] * inputV[i]

	return np.array(deltaW)

def addDeltaW(w, deltaW, layer):
	for l in range(layer.shape[0] - 1):
		for j in range(1, layer[l + 1]):
			for i in range(layer[l]):
				w[l][j - 1][i] += deltaW[l][j - 1][i]
	return w

def backpropagation(layer, X, Y):
	layer[layer.shape[0] - 1] += 1

	w = initializeW(layer, 1)
	delta = initializeDelta(layer)
	print delta
	outputs = initializeDelta(layer)

	errorThresh = 0.05
	eta = 0.01

	error = 15

	while error > errorThresh:
		for i in range(X.shape[0]):
			x = X[i]
			#modify outputs
			outputs = feedForward(w, x, layer)

			#modify delta
			delta = modifyDelta(Y[i], w, outputs, layer)

			#update deltaW
			deltaW = computeDeltaW(eta, delta, outputs, x)

			#modify w
			w = addDeltaW(w, deltaW, layer)	
		#update error
		error = computeError(Y, outputs[layer.shape[0] - 2])
	print w

backpropagation(np.array([3, 3, 1]), 
	np.array([[-1, 0, 0], [-1, 0, 1], [-1, 1, 0], [-1, 1, 1]]), 
	np.array([[0], [1], [1], [0]]))