from ..twitter.getWords import *

def getFeatureVector(tweet, wordList):
	wordsInTweet = getWords(tweet);
	featureVector = []
	for w in wordList:
		if w in wordsInTweet:
			featureVector.append(1)
		else:
			featureVector.append(0)
	return featureVector