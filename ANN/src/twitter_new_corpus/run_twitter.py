from ..twitter.getWords import *
from ..twitter.getAnnotation import *
from ..twitter.getWordList import *
from ..twitter.weight import *
from ..backpropagation.backpropagation import *

def run_twitter(tweet):
	temp = []
	temp.append(-1)
	if "!" in tweet:
		temp.append(1)
		temp.append(1)
		temp.append(1)
		temp.append(1)
	else:
		temp.append(0)
		temp.append(0)
		temp.append(0)
		temp.append(0)

	if "n't" in tweet:
		temp.append(1)
		temp.append(1)
		temp.append(1)
		temp.append(1)
	else:
		temp.append(0)
		temp.append(0)
		temp.append(0)
		temp.append(0)

	words = getWords(tweet)

	wordList = loadWordList("wordList")
	for w in wordList:
		if w in words:
			temp.append(1)
		else:
			temp.append(0)


	layer1 = np.array([np.array(temp).shape[0], 4])
	w1 = initializeW(layer1, 1)
	store_weight(w1, layer1)
	load_weight('weights2', w1, layer1)
	outputs = feedForward(w1, np.array(temp), layer1)

	max_val = 0
	max_ind = 0
	for j in range(3):
		if(outputs[outputs.shape[0] - 1][j] > max_val):
			max_val = outputs[outputs.shape[0] - 1][j]
			max_ind = j

	if(max_ind == 0):
		print "Positive"
	elif(max_ind == 1):
		print "Negative"
	else:
		print "Neutral"


run_twitter('A day without laughter is a day wasted !!!:D http://fb.me/2fBy7e22Z')
run_twitter('chinese government official dies on first day of job due to drinking water')
run_twitter('let\'s walk')
run_twitter('GoT Season 4 synopsis.. Basically pic.twitter.com/5Qo6iuEToj')
