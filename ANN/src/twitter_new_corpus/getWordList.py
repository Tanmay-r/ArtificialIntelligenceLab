from ..twitter.getWords import *
import numpy as np
import re

_digits = re.compile('\d')
def contains_digits(d):
    return bool(_digits.search(d))

def isValid(w):
	valid = 1
	if(len(w) <= 2):
		valid = 0
	if contains_digits(w):
		valid = 0
	return valid

def getWordList(file1, file2, file3, param):
	wordList = []
	f = open(file1, 'r')
	data = f.read()
	f.close()

	word_count = {}
	for line in data.split('\n'):
		words = getWords(line)
		for w in words:
			if isValid(w):
				if w not in wordList:
					wordList.append(w.lower())
					word_count[w.lower()] = 1
				else:
					word_count[w.lower()] = word_count[w.lower()] + 1
	if(param >= 2):
		f = open(file2, 'r')
		data = f.read()
		f.close()

	
		for line in data.split('\n'):
			words = getWords(line)
			for w in words:
				if isValid(w):
					if w not in wordList:
						wordList.append(w.lower())
						word_count[w.lower()] = 1
					else:
						word_count[w.lower()] = word_count[w.lower()] + 1
	if(param == 3):
		f = open(file3, 'r')
		data = f.read()
		f.close()

		for line in data.split('\n'):
			words = getWords(line)
			for w in words:
				if isValid(w):
					if w not in wordList:
						wordList.append(w.lower())
						word_count[w.lower()] = 1
					else:
						word_count[w.lower()] = word_count[w.lower()] + 1

	newWordList = []
	for w in wordList:
		if(word_count[w] > 1):
			newWordList.append(w)

	np.random.shuffle(newWordList)
	return np.array(newWordList)
