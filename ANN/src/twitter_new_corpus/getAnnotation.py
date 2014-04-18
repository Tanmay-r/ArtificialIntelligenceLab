def getAnnotation(line):
	returnLine = line.split("$$")
	if(len(returnLine) > 2):
		annot = returnLine[1][0:3]
		return [returnLine[0], returnLine[1]]
	return ["", "invalid"]

