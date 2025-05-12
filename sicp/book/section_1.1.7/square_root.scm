(define tolerance 0.01)

(define (avg x y)
  	(/ (+ x y) 2.0))

(define (mod x)
	(if (< x 0)
	    (* x -1)
	    x))

(define (guess_checker guess x)
	(if (< (mod (- (* guess guess) x)) tolerance)
	    #t
	    #f))

(define (square_root guess x)
  	(if (guess_checker guess x)
	    guess
	    (square_root (avg guess (/ x guess)) x)))

(square_root 1 99999999999999999999)	
