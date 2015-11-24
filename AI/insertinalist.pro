
%
% 12BCE023
% This progran takes a list of integers and an integer for INSERT as an input and then inserts it at a desired position for its existance
%
/*
domains
	LI = integer*
	B=integer
predicates
	insert(B,LI,LI)
clauses
	insert(B,List,[B|List]).
*/
domains
	LI = integer*
	B=integer
predicates
	insert(B,LI,LI)
	insert_1(B,LI,LI)
	%insert_2(B,LI,LI)
clauses
	insert_2(B,L1,[]):-
		write("L1=",L1).
	insert_2(B,L1,[H2|T2]):-
		insert_2(B,[H2|L1],T2).
	insert_1(B,[],L2):-
		insert_2(B,[B],L2).
	insert_1(B,[H1|T1],L2):-
		insert_1(B,T1,[H1|L2]).
	insert(B,L1,[]):-
		insert_1(B,L1,[]).
		
