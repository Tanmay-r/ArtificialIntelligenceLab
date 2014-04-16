
zero(0).
one(1).


notGate(X1, Z):- zero(X1), Z is 1; one(X1), Z is 0.
orGate(X1, X2, Z):- zero(X1), zero(X2), Z is 0; one(X1), zero(X2), Z is 1;zero(X1), one(X2), Z is 1;one(X1), one(X2), Z is 1.
norGate(X1, X2, Z):- zero(X1), zero(X2), Z is 1; one(X1), zero(X2), Z is 0;zero(X1), one(X2), Z is 0;one(X1), one(X2), Z is 0.
andGate(X1, X2, Z):- zero(X1), zero(X2), Z is 0; one(X1), zero(X2), Z is 0;zero(X1), one(X2), Z is 0;one(X1), one(X2), Z is 1.
nandGate(X1, X2, Z):- zero(X1), zero(X2), Z is 1; one(X1), zero(X2), Z is 1;zero(X1), one(X2), Z is 1;one(X1), one(X2), Z is 0.
xorGate(X1, X2, Z):- zero(X1), zero(X2), Z is 0; one(X1), zero(X2), Z is 1;zero(X1), one(X2), Z is 1;one(X1), one(X2), Z is 0.
xnorGate(X1, X2, Z):- zero(X1), zero(X2), Z is 1; one(X1), zero(X2), Z is 0;zero(X1), one(X2), Z is 0;one(X1), one(X2), Z is 1.


tbpalindrome(0,0,0,0,0,0).
tbpalindrome(0,0,0,0,1,0).
tbpalindrome(0,0,0,1,0,0).
tbpalindrome(0,0,0,1,1,0).
tbpalindrome(0,0,1,0,0,1).
tbpalindrome(0,0,1,0,1,0).
tbpalindrome(0,0,1,1,0,0).
tbpalindrome(0,0,1,1,1,0).
tbpalindrome(0,1,0,0,0,0).
tbpalindrome(0,1,0,0,1,0).
tbpalindrome(0,1,0,1,0,1).
tbpalindrome(0,1,0,1,1,0).
tbpalindrome(0,1,1,0,0,0).
tbpalindrome(0,1,1,0,1,0).
tbpalindrome(0,1,1,1,0,1).
tbpalindrome(0,1,1,1,1,0).

tbpalindrome(1,0,0,0,0,0).
tbpalindrome(1,0,0,0,1,1).
tbpalindrome(1,0,0,1,0,0).
tbpalindrome(1,0,0,1,1,0).
tbpalindrome(1,0,1,0,0,0).
tbpalindrome(1,0,1,0,1,1).
tbpalindrome(1,0,1,1,0,0).
tbpalindrome(1,0,1,1,1,0).
tbpalindrome(1,1,0,0,0,0).
tbpalindrome(1,1,0,0,1,0).
tbpalindrome(1,1,0,1,0,0).
tbpalindrome(1,1,0,1,1,1).
tbpalindrome(1,1,1,0,0,0).
tbpalindrome(1,1,1,0,1,0).
tbpalindrome(1,1,1,1,0,0).
tbpalindrome(1,1,1,1,1,1).



palindrome:- xnorGate(A,E,Z1), xnorGate(B,D,Z2), andGate(Z1,Z2,Z3),  (zero(C); one(C)), (tbpalindrome(A,B,C,D,E,Z3); (not(tbpalindrome(A,B,C,D,E,Z3)), out('False Case: '), out(A),out(B),out(C), out(D), out(E), out(Z3), outln)).


tbfulladder(0,0,0,0,0).
tbfulladder(0,0,1,1,0).
tbfulladder(0,1,0,1,0).
tbfulladder(0,1,1,0,1).
tbfulladder(1,0,0,1,0).
tbfulladder(1,0,1,0,1).
tbfulladder(1,1,0,0,1).
tbfulladder(1,1,1,1,0).
fulladder(A,B,C, Z2, Z6):- xorGate(A, B, Z1), xorGate(Z1, C, Z2), andGate(A, B, Z3), orGate(A,B,Z4), andGate(Z4, C, Z5), orGate(Z3, Z5, Z6), tbfulladder(A,B,C,Z2,Z6).
full:- xorGate(A, B, Z1), xorGate(Z1, C, Z2), andGate(A, B, Z3), orGate(A,B,Z4), andGate(Z4, C, Z5), orGate(Z3, Z5, Z6), (tbfulladder(A,B,C,Z2,Z6);  not(tbfulladder(A,B,C,Z2,Z6)), out('False Case: '), out(A),out(B),out(C),out(Z2),out(Z6), outln).
out(X):- write(X),!.
outln:- nl,!.

tbgiven(0,0,0,1).
tbgiven(0,0,1,0).
tbgiven(0,1,0,1).
tbgiven(0,1,1,0).
tbgiven(1,0,0,0).
tbgiven(1,0,1,1).
tbgiven(1,1,0,0).
tbgiven(1,1,1,1).
given:- xnorGate(A,C,Z), (zero(B); one(B)), (tbpalindrome(A,B,C,Z); (not(tbpalindrome(A,B,C,Z)), out('False Case: '), out(A),out(B),out(C),out(Z), outln)).



tbmajority(0,0,0,0,0,0).
tbmajority(0,0,0,0,1,0).
tbmajority(0,0,0,1,0,0).
tbmajority(0,0,0,1,1,0).
tbmajority(0,0,1,0,0,0).
tbmajority(0,0,1,0,1,0).
tbmajority(0,0,1,1,0,0).
tbmajority(0,0,1,1,1,1).
tbmajority(0,1,0,0,0,0).
tbmajority(0,1,0,0,1,0).
tbmajority(0,1,0,1,0,0).
tbmajority(0,1,0,1,1,1).
tbmajority(0,1,1,0,0,0).
tbmajority(0,1,1,0,1,1).
tbmajority(0,1,1,1,0,1).
tbmajority(0,1,1,1,1,1).

tbmajority(1,0,0,0,0,0).
tbmajority(1,0,0,0,1,0).
tbmajority(1,0,0,1,0,1).
tbmajority(1,0,0,1,1,1).
tbmajority(1,0,1,0,0,0).
tbmajority(1,0,1,0,1,1).
tbmajority(1,0,1,1,0,1).
tbmajority(1,0,1,1,1,1).
tbmajority(1,1,0,0,0,0).
tbmajority(1,1,0,0,1,1).
tbmajority(1,1,0,1,0,1).
tbmajority(1,1,0,1,1,1).
tbmajority(1,1,1,0,0,1).
tbmajority(1,1,1,0,1,1).
tbmajority(1,1,1,1,0,1).
tbmajority(1,1,1,1,1,1).


majority:- orGate(C,D,Z1), orGate(A,E,Z2), andGate(B,Z1,Z3), andGate(Z2,Z3,Z4), 
		   andGate(D,B,Z5), andGate(E,D,Z6), andGate(A,D,Z7), andGate(A,E,Z8),
		    orGate(Z5,Z6,Z14),
		   orGate(Z7,Z8,Z15), orGate(Z14,Z15,Z16), andGate(C,Z16,Z17),
		   andGate(A,E,Z9), orGate(B,D,Z10), andGate(Z9,Z10,Z11), 
		   orGate(Z4,Z17,Z12), orGate(Z11,Z12,Z13), (tbmajority(A,B,C,D,E,Z13); (not(tbmajority(A,B,C,D,E,Z13)), out('False Case: '), out(A),out(B),out(C), out(D), out(E), out(Z13), outln)).


























