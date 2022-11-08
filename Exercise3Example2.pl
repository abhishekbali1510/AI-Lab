parent( pam, bob).
parent( tom, bob).
parent( tom, liz).
parent( bob, ann).
parent( bob, pat).
parent( pat, jim).
female( pam).
male( tom).
male( bob).
female( liz).
female( pat).
female( ann).
male( jim).


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