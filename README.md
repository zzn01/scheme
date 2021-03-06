Another Dirty Scheme Interpreter
================================

> *"We were actually trying to build something complicated and 
discovered, serendipitously, that we had accidentally designed 
something that met all our goals but was much simpler than we
had intended....we realized that the lambda calculus--a small,
simple formalism--could serve as the core of a powerful and 
expressive programming language." -- Sussman and Steele*

Writing a Scheme interpreter is easy, and more importantly,
it is fun.

Features:
-----------------
+ lambda, of course
+ integer(32 bit), floating-point numbers, string, symbol, boolean,
character, pair, vector
+ basic number/mathematical functions
+ basic input/output support
+ basic string/character procedures
+ vector procedures in R5RS
+ most list procedures in MIT Scheme
+ cond, if, let, begin, and, or, define, set!, apply, eval...
+ var-arg
+ mark-sweep garbage collector
+ continuation
+ macro(define-macro)
+ promise(delay, force)

Install:
---------
`$ make`   
`$ sudo make install`   
`$ asc`  
If you don't like it, `$ sudo make uninstall`

Documentation:
--------------
If you already know Scheme, just start typing code in the REPL. 
Or you can read the R5RS.
[here](http://www.schemers.org/Documents/Standards/R5RS/HTML)

Thanks for *Peter Michaux's* excellent 
[introduction series.](http://peter.michaux.ca/articles/scheme-from-scratch-introduction)

Todo list:
---------------
+ rename files, remove "sc" prefix **[DONE]**
+ add gc support **[DONE]**
+ add cache for integer objects **[DONE]**
+ add cache for character objects **[DONE]**
+ add floating point support **[DONE]**
+ add var-arg support **[DONE]**
+ improve logger **[DONE]**
+ modify equal? eq? eqv? **[DONE]**
+ add / primitive procedure **[DONE]**
+ add math primitive functions **[DONE]**
+ add character procedures **[DONE]**
+ add gcd, lcm procedures **[DONE]**
+ add (runtime) procedure **[DONE]**
+ add more list procedures **[DONE]**
+ add string functions **[DONE]**
+ add (display) procedure **[DONE]**
+ improve io support **[DONE]**
+ add vector support **[DONE]**
+ rewrite environment using rbtree(variable lookup is too slow) **[DONE] ~2x speedup**
+ call/cc **[DONE]**
+ macro support **[DONE]**
+ command line options **[DONE]**
+ make install **[DONE]**
+ add case, do **[DONE]**
+ prettify quote output **[DONE]**
+ stream support
