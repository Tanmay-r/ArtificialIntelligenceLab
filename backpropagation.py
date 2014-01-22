'''
Created on Jan 21, 2014

@author: Tanmay
'''
import numpy as np
import math

def computeError(Y, Ypredicted):
	error = 0
	print Ypredicted
	for i in range(Ypredicted.shape[0]):
		error += 0.5*(Y[i] - Ypredicted[i])*(Y[i] - Ypredicted[i])
	return error

def initializeW(layer):
	layerCount = layer.shape[0]

	w = []
	prev = layer[0]
	for l in range(1,layerCount):
		wlayer = []
		for j in range(layer[l]):
			wperceptron = []
			for i in range(prev):
				wperceptron.append(0)
			prev = layer[l]
			wlayer.append(np.array(wperceptron))
		w.append(np.array(wlayer))
	return np.array(w)

def initializeDelta(layer):
	layerCount = layer.shape[0]

	delta = []
	for i in layer:
		deltaLayer = []
		for j in range(i):
			deltaLayer.append(0)
		delta.append(np.array(deltaLayer))

	return np.array(delta)

def initializeOutput(layer, X):
	outputs = initializeDelta(layer)
	outputs[0] = X 
	return outputs

def sigmoid(net):
	return 1/(1 + math.exp(-net))

def evaluate(x, w, layer):
	for i in range(layer.shape[0]):
		

def backPropagation(layer, X, Y):
	errorThresh = 0.05

	w = initializeW(layer)
	delta = initializeDelta(layer)
	
	outputs = initializeOutput(layer, X)

	error = computeError(Y, outputs[layer.shape[0] - 1])
	print error
	Iteration = 0
	while error > errorThresh:
		Iteration += 1
		print "w =", w
		print "delta =", delta
		print "outputs =", outputs
		#modify delta
		#for outer layer
		for i in range(layer[layer.shape[0] - 1]):
			delta[layer.shape[0] - 1][i] = (Y[i] - outputs[layer.shape[0] - 1][i])*outputs[layer.shape[0] - 1][i]*(1 - outputs[layer.shape[0] - 1][i])
		for i in range(layer.shape[0] - 2, 0):
			for j in range(layer[i]):
				delta[i][j] = 0
				for k in range(layer[i+1]):
					delta[i][j] += w[i + 1][k][j] * delta[i+1][k] * outputs[i][j]*(1 - outputs[i][j])

		#modify w
		for l in range(layer.shape[0] - 1, 1):
			for j in range(layer[l]):
				for i in range(layer[l - 1]):
					w[l][j][i] += eta * delta[l][j] * outputs[l - 1][i]

		#modify outputs
		for l in range(layer.shape[0] - 1, 1):
			for j in range(layer[l]):
				net = 0
				for i in range(layer[l - 1]):
					net += outputs[l - 1][i]*w[l][j][i]
					outputs[l][j] = sigmoid(net)
		error = computeError(Y, outputs[layer.shape[0] - 1])
		print "Iteration number =", Iteration
		print error

backPropagation(np.array([3, 3, 1]), 
	np.array([[-1, 0, 0], [-1, 0, 1], [-1, 1, 0], [-1, 1, 1]]), 
	np.array([0, 1, 1, 0]))