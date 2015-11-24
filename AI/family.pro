%trace

%Created by Dhrushit Raval 12BCE023
%
% this program uses some predefined facts of who is father and mother of who and so on
% it then finds out using these facts, who is brother,sister,aunty,uncle,bhabhi, grandson and grand daughter of who
%
domains
	
predicates
	father(symbol,symbol)
	mother(symbol,symbol)
	male(symbol)
	female(symbol)
	wife(symbol,symbol)
	uncle(symbol,symbol)
	sister(symbol,symbol)
	brother(symbol,symbol)
	aunty(symbol,symbol)
	bhabhi(symbol,symbol)
	cousin(symbol,symbol)
	gs(symbol,symbol)
	gd(symbol,symbol)
	parent(symbol,symbol)
	start()
clauses
	father(vithhaldas,dhanjiBhai).%vithhaldas is father of dhanjiBhai
	father(vithhaldas,chuniBhai).
	father(dhanjiBhai,harshad).
	father(dhanjiBhai,darshan).
	father(dhanjiBhai,nilam).
	father(dhanjiBhai,kiran).
	father(chuniBhai,kamleshbhai).
	mother(prabhaben,harshad).
	
	male(harshad).
	male(darshan) .
	male(dhanjibhai).
	male(chunibhai ).
	
	female(nilam).
	female(kiran).
	female(prabhaben).
	female(nimishaben).
	female(kokilaben).

	wife(prabhaben,dhanjiBhai).
	wife(nimishaben,kamleshbhai).
	wife(kokilaben,chuniBhai).

	start:-
		makewindow(1,7,7,"interaction window",0,2,11,43),
		sister(_,_),
		write("\n"),
		brother(_,_),
		write("\n"),
		aunty(_,_),
		write("\n"),
		uncle(_,_),
		write("\n"),
		bhabhi(_,_),
		gs(_,_),
		write("\n"),
		gd(_,_),
		write("\n"),
		keypressed().
	sister(X,Y):-
		father(A,X),
		father(A,Y),
		female(X),
		not(X=Y),
		write(X," is sister of ",Y,"\n"),fail.
	brother(X,Y):-
		father(A,X),
		father(A,Y),
		male(X),
		not(X=Y),
		write(X," is brother of ",Y,"\n"),
		fail.
	uncle(X,Y):-
		male(X),
		father(A,Y),
		father(B,A),
		father(B,Z),
		Z<>A,
		write(X," is uncle of ",Y,"\n"),fail.
	aunty(X,Y):-
		female(X),
		uncle(A,Y),
		wife(X,A),
		write(X," is aunty of ",Y,"\n"),fail.
	
	bhabhi(X,Y):-
		female(X),
		brother(A,Y),
		wife(X,A),
		write(X," is bhabhi of ",Y,"\n"),fail.
	
	cousin(X,Y):-
		father(A,X),
		father(B,Y),
		mother(C,X),
		mother(D,Y),
		brother(A,B);
		brother(A,D);
		brother(B,C),
		write(X," is cousin of ",Y,"\n"),fail.
	parent(X,Y):-
		father(X,Y);
		mother(X,Y).
	gs(X,Y):-
		male(X),
		parent(A,X),
		parent(Y,A),
		write(X," is grand son of ",Y,"\n"),fail.
	gd(X,Y):-
		female(X),
		parent(A,X),
		parent(Y,A),
		write(X," is grand daughter of ",Y,"\n"),fail.
GOAL
	start.
