from ..backpropagation.backpropagation import *
from ..backpropagation.buildInput import *
from ..iris.generateTrainingData import *
import numpy as np
import math

M = 0.5
eta = 0.01
errorThresh = 0.2

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

