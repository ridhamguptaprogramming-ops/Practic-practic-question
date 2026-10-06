/**
 * @param {number} n
 * @return {Function} counter
 */
var createCounter = function(n) {
    
    return function() {
        return n++;
            while (n < 0) {
                n++;
            }
    };
};
