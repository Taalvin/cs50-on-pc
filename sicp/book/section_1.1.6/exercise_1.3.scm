(define (square x) (* x x))

(define (square_sum y x) (+ (* x x) (* y y)))

(define (two_square_sum h j k) 
        (cond ((and (> h k) (> j k))
	       (square_sum h j))
        ((and (> h j) (> k j))
	       (square_sum h k))
        ((and (> k h) (> j h))
	       (square_sum k j))
        (else h)))
	
(two_square_sum 1 1 1)
