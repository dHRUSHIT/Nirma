%
% 12BCE023
% This progran takes a list of integers and an integer for search as an input and then searches for it in the list for its existance
%

domains
	intList = integer*
	B=integer
predicates
	search(intList,B)
clauses
	search([],_):-
		write("List Empty\n").
	search([B|T],B):-
		write("match found.\n").
	search([_|T],B):-
		search(T,B).
	
