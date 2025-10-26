/**
 * @param {Array} arr
 * @param {number} depth
 * @return {Array}
 */
var flat = function (arr, n) {
    if(n===0){
        return arr;
    }
    const result=[];
    for(const element of arr){
        //check if the element is part of array and depth>0
        if(Array.isArray(element) && n>0){
            const flattened=flat(element, n-1);
            result.push(...flattened);
        }
        else{
            result.push(element);
        }
    }
        return result;
};