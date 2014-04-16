signal(A):- read(A).
connected(_,_,X,Y) :- X is Y.
type(_,orgate,X1,X2,Z) :- ((X1=0, X2=0, Z is 0) ; ((X1=1; X2=1), Z is 1)).
type(_,andgate,X1,X2,Z) :- ((X1=1, X2=1, Z is 1) ; ((X1=0; X2=0), Z is 0)).
type(_,xorgate,X1,X2,Z) :- ((X1=X2, Z is 0) ; (not(X1 = X2), Z is 1)).
type(_, notgate, X, Z) :- (X =0, Z is 1 ) ; (X=1, Z is 0).
type(_,nandgate,X1,X2,Z) :- (X1=1, X2=1, Z is 0) ; ((X1=0; X2=0), Z is 1).
type(_,norgate,X1,X2,Z) :- ((X1=1, X2=1, Z is 1) ; ((X1=0; X2=0), Z is 0)).
type(_,xnorgate,X1,X2,Z) :- ((X1=X2, Z is 1) ; (not(X1 = X2), Z is 0)).
connected1(_, out, _).
out(X) :- write('output= '), write(X),nl, !.
