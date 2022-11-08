female(mary).
female(sandra).
female(juliet).
female(lisa).
male(peter).
male(paul).
male(john).
male(bob).
male(harry).
parent(bob, lisa).
parent(bob, paul).
parent(bob, mary).
parent(juliet, lisa).
parent(juliet, paul).
parent(juliet, mary).
parent(peter, harry).
parent(lisa, harry).
parent(mary, john).
parent(mary, sandra).


brother(First,Second):-
    parent(Third,First),
    parent(Third,Second),
    male(First).


sister(First,Second):-
    parent(Third,First),
    parent(Third,Second),
    female(First).

mother(First,Second):-
    parent(First,Second),
    female(First).

grandparent(First,Second):-
    parent(First,Third),
    parent(Third,Second).
