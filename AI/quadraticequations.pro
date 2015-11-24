%trace

%
% the quadratic function A*X^2 + B*X + C = 0 is considered
% The program first asks for A then for B and then for C
% It automatically calculates the value of the B^2-4*A*C and checks if it is greater than 0 or not
% If greater than 0 then it calculates the real roots
% If not then displays that the roots are imaginary
%

domains

predicates
ask()
calcroots(integer,integer,integer,integer)
go()

clauses
	ask():-
		write("Equation : \nAx^2 + Bx + C = 0\n"),
		write("Enter A : "),
		readint(A),
		write("Enter B : "),
		readint(B),
		write("Enter C : "),
		readint(C),
		D = B*B-4*A*C,
		calcroots(A,B,C,D).
		
	calcroots(X,Y,Z,R):-
		R >= 0,
		K = sqrt(R),
		R1 = (-Y + K)/(2*X),
		R2 = (-Y - K)/(2*X),
		write("\nRoot 1 is "),write(R1),
		write("\nRoot 2 is "),write(R2),nl.	
	calcroots(X,Y,Z,R):-
		R < 0,
		write("complex roots \n"),nl.	
	
	
	go():-
		ask(),
		go().
GOAL
	go()
