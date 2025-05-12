(define (hanoi n)
  	(if (< n 2)
	    n
	    (+ (* (hanoi (- n 1)) 2) 1)))

(hanoi 6)
