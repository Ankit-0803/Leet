/**
 * @param {number[]} nums
 * @return {void}
 */
var ArrayWrapper = function(nums) {
    //store the array
    this.nums=nums;
};

/**
 * @return {number}
 */
ArrayWrapper.prototype.valueOf = function() {
    //returns the sum of array elements
    return this.nums.reduce((sum, num)=>sum+num, 0);
    
}

/**
 * @return {string}
 */
ArrayWrapper.prototype.toString = function() {
    //return string representation like ["1,2,3"]
    return `[${this.nums.join(",")}]`;
}

/**
 * const obj1 = new ArrayWrapper([1,2]);
 * const obj2 = new ArrayWrapper([3,4]);
 * obj1 + obj2; // 10
 * String(obj1); // "[1,2]"
 * String(obj2); // "[3,4]"
 */