def splitData(file1):
	f = open(file1, 'r')
	data = f.read()
	f.close()

	tweets = data.split('\n')

	trainFile = []
	testFile = []
	for i in range(5):
		trainFile.append(open("combinedCorpusTrain" + str(i), 'w'))
		testFile.append(open("combinedCorpusTest" + str(i), 'w'))
	
	start_index = 0
	for i in range(len(tweets)):
		for j in range(5):
			if(j != start_index):
				trainFile[j].write(tweets[i])
				trainFile[j].write("\n")
			else:
				testFile[j].write(tweets[i])
				testFile[j].write("\n")
		start_index += 1
		start_index = start_index % 5
			
			

	for i in range(5):
		trainFile[i].close()
		testFile[i].close()

splitData("data/twitter/twitter_data/combinedCorpus")
