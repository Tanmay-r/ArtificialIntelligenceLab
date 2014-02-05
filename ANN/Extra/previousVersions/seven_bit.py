import numpy as np
a = np.asarray([1,1,1,1,1,1,0])
def zero(a):
	if(a[0] and a[1] and a[2] and a[3] and a[4] and a[5] and not a[6]):
		return 1
	else:
		return 0

def one(a):
	if(not a[0] and a[1] and a[2] and not a[3] and not a[4] and not a[5] and not a[6]):
		return 1
	else:
		return 0		

def two(a):
	if(a[0] and a[1] and not a[2] and a[3] and a[4] and not a[5] and a[6]):
		return 1
	else:
		return 0
def three(a):
	if(a[0] and a[1] and a[2] and a[3] and not a[4] and not a[5] and a[6]):
		return 1
	else:
		return 0
def four(a):
	if(not a[0] and a[1] and a[2] and not a[3] and not a[4] and a[5] and a[6]):
		return 1
	else:
		return 0
def five(a):
	if(a[0] and not a[1] and a[2] and a[3] and not a[4] and a[5] and a[6]):
		return 1
	else:
		return 0

def six(a):
	if(a[0] and not a[1] and a[2] and a[3] and a[4] and a[5] and a[6]):
		return 1
	else:
		return 0

def seven(a):
	if(a[0] and a[1] and a[2] and not a[3] and not a[4] and not a[5] and not a[6]):
		return 1
	else:
		return 0
def eight(a):
	if(a[0] and a[1] and a[2] and a[3] and a[4] and a[5] and a[6]):
		return 1
	else:
		return 0
def nine(a):
	if(a[0] and a[1] and a[2] and a[3] and not a[4] and a[5] and a[6]):
		return 1
	else:
		return 0


print zero(a)

