(princ "Kendall Is forcing me to do eLisp and I do not like it.")


(+ 3(- 5 2))
6

(setq name "Kendall")
"Kendall"

"Kendall"



(insert "Hello " name )
Hello Kendall

(defun hello () (insert name " IS PUSHY."))
show

(show)
Kendall IS PUSHY.nil

(show)
Kendall" IS PUSHY"

(defun show2 (name) (insert "Good Bye " name))
show2


(show2 name)
Good Bye Kendall

(let ((local-name "Loser"))
  (insert "ELISp is  a " local-name))

ELISp is  a Loser
Kendall is  a Loser


(read-from-minibuffer "Enter your Name: ")


"This is a test"


(defun greeting (name)
  (let ((your-name "David"))
    (insert (format "Hello %s!\nI am %s.\n" name your-name))))
(greeting name)

Hello Kendall!
I am David.

(greeting "Beautiful Lady")
Hello Beautiful Lady!
I am David.


;;Lets store a list of names
(setq list-of-names '("David" "Kendall" "Kate" "My Future Wife"))

;;Get first item out of a list
(car list-of-names)


;;Get a list of al but the first
(cdr list-of-names)

;;Pushes at the front of the list
(push "Jack Sparrow" list-of-names)

(mapcar 'greeting list-of-names)
Hello Jack Sparrow!
I am David.
Hello David!
I am David.
Hello Kendall!
I am David.
Hello Kate!
I am David.
Hello My Future Wife!
I am David.


