/**
 * @param {Function} fn
 * @param {number} t milliseconds
 * @return {Function}
 */
var debounce = function(fn, t) {
    //store timeout
    let timeoutId;
    return function(...args) {
        //cancel any pending execution
        clearTimeout(timeoutId);
        //schedule new execution
        timeoutId=setTimeout(()=>{
            fn(...args);
        }, t);
        
    };
};

/**
 * const log = debounce(console.log, 100);
 * log('Hello'); // cancelled
 * log('Hello'); // cancelled
 * log('Hello'); // Logged at t=100ms
 */