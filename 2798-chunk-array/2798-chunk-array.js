/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array}
 */
var chunk = function(arr, size) {
    const result=[];
    for(let i=0; i<arr.length; i+=size){
        //extract chunk from current position
        result.push(arr.slice(i, i+size));
    }
    return result;
};
