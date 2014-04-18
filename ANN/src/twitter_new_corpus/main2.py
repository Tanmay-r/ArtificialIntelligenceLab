from ..twitter.getWords import *
from ..twitter.getAnnotation import *
from ..twitter.getWordList import *
from ..twitter.weight import *
from ..backpropagation.backpropagation import *

def generateTrainingData(file1):
	Y = []
	X = []

	f = open(file1, 'r')
	data = f.read()
	f.close()

	for line in data.split('\n'):
		temp = []
		temp.append(-1)
		if "!" in line:
			temp.append(1)
			temp.append(1)
			temp.append(1)
			temp.append(1)
		else:
			temp.append(0)
			temp.append(0)
			temp.append(0)
			temp.append(0)

		if "n't" in line:
			temp.append(1)
			temp.append(1)
			temp.append(1)
			temp.append(1)
		else:
			temp.append(0)
			temp.append(0)
			temp.append(0)
			temp.append(0)

		[line, annotation] = getAnnotation(line)
		words = getWords(line)

		for w in wordList:
			if w in words:
				temp.append(1)
			else:
				temp.append(0)
		
		if (annotation == "pos"):
			X.append(np.array(temp))
			Y.append(np.array([1, 0, 0]))
		elif (annotation == "neg"):
			X.append(np.array(temp))
			Y.append(np.array([0, 1, 0]))
		elif (annotation == "neu"):
			X.append(np.array(temp))
			Y.append(np.array([0, 0, 1]))

	return [np.array(X), np.array(Y)]

M = 0.8
eta = 0.9
errorThresh = 550

print "Creating list of words..."
wordList = getWordList("data/twitter/twitter_data/combinedCorpus", " " , " " , 1)

trainFile = "data/twitter/twitter_data/combinedCorpus"
[X, Y] = generateTrainingData(trainFile)
layer1 = np.array([X[0].shape[0], 4])
w1 = initializeW(layer1, 1)
print w1.shape
#store_weight(w1, layer1)
#backpropagation(layer1, X, Y, w1, eta, M, errorThresh)
store_weight(w1, layer1)

'''
correct_total = 0
total_total = 0
for k in range(5):
	trainFile = "data/twitter/twitter_data/combinedCorpusTrain" + str(k)
	testFile = "data/twitter/twitter_data/combinedCorpusTest" + str(k)
	[X, Y] = generateTrainingData(trainFile)

	layer1 = np.array([X[0].shape[0], 4])
	w1 = initializeW(layer1, 1)
	store_weight(w1, layer1)
	load_weight(w1,layer1)
	backpropagation(layer1, X, Y, w1, eta, M, errorThresh)

	[Xtest, Ytest] = generateTrainingData(testFile)

	correct = 0
	total = 0
	for i in range(Ytest.shape[0]):
			total = total + 1
			X1 = Xtest[i]
			outputs = feedForward(w1, X1, layer1)	
			max_val = 0
			max_ind = 0
		
			for j in range(3):
				if(outputs[outputs.shape[0] - 1][j] > max_val):
					max_val = outputs[outputs.shape[0] - 1][j]
					max_ind = j

			if(Ytest[i][max_ind] == 1):
				correct = correct + 1

	print "Dataset ", k, " ", correct, " ", total, correct/(total * 0.01)
	correct_total += correct
	total_total += total

print "Total ", correct_total, " ", total_total, correct_total/(total_total * 0.01)
'''


