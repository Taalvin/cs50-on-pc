(define (factorial x) 
        (if (= x 1)
            1
            (* x (factorial (- x 1)))))

(define (fact n product counter)
        (if (< n counter)
            product
            (fact n (* counter product) (+ counter 1))))

(define (factorial_v2 n)
        (fact 1 1))
