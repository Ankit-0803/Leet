/**
 * @param {Array} arr
 * @param {Function} fn
 * @return {Array}
 */
var sortBy = function(arr, fn) {
    //fn(a)-fn(b) creates ascending order
    return arr.sort((a,b)=>fn(a)-fn(b));
};