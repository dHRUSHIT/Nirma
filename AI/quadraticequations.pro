
%
% 12BCE023
% The program first starts by asking for an input that determines if the user wants to add or substrace or multiply or divide
% Then then it takes input for the operands
% Once done, it calculates the value of the arithematic operation and then displays the value that is generated
%
%

domains

predicates
choose()
adds()
subs()
muls()
divs()

calcit(integer)

clauses
choose():-
	write("1. Addition\n2. Substraction\n3. Multiplication\n4. Division\n"),
	readint(C),
	calcit(C).
	calcit(1):- 
		write("Addition A+B\n"),adds().
	calcit(2):- 
		write("Substraction A-B\n"),subs().
	calcit(3):- 
		write("Multiplication A*B\n"),
		muls().
	calcit(4):- 
		write("Division A/B\n"),
		divs().


	adds():-
		write("enter A and B : "),
		readint(A),
		readint(B),
		C=A+B,
		write(C).
	subs():-
		write("enter A and B : "),
		readint(A),
		readint(B),
		C=A-B,
		write(C).
	muls():-
		write("enter A and B : "),
		readint(A),
		readint(B),
		C=A*B,
		write(C).
	divs():-
		write("enter A and B : "),
		readint(A),
		readint(B),
		C=A/B,
		write(C).
	
GOAL
	choose().
