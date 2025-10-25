var TimeLimitedCache = function() {
    this.cache=new Map();
};

/** 
 * @param {number} key
 * @param {number} value
 * @param {number} duration time until expiration in ms
 * @return {boolean} if un-expired key already existed
 */
TimeLimitedCache.prototype.set = function(key, value, duration) {
    const haskey= this.cache.has(key);
    if(haskey){
        //get the existing key as it exists
        const existingEntry=this.cache.get(key);
        //clear the old timeout that was set for this key & set a new timeout
        clearTimeout(existingEntry.timeoutId);

    }
    const timeoutId= setTimeout(()=>{
        this.cache.delete(key);
    }, duration);
    //store the value along with its timeout ID
    this.cache.set(key, {
        value:value,
        timeoutId:timeoutId
    });
    return haskey;
};

/** 
 * @param {number} key
 * @return {number} value associated with key
 */
TimeLimitedCache.prototype.get = function(key) {
    if(this.cache.has(key)){
        return this.cache.get(key).value;
    }
    return -1;
};

/** 
 * @return {number} count of non-expired keys
 */
TimeLimitedCache.prototype.count = function() {
    return this.cache.size;
};

/**
 * const timeLimitedCache = new TimeLimitedCache()
 * timeLimitedCache.set(1, 42, 1000); // false
 * timeLimitedCache.get(1) // 42
 * timeLimitedCache.count() // 1
 */