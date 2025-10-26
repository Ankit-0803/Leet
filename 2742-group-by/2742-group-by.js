/**
 * @param {Function} fn
 * @return {Object}
 */
Array.prototype.groupBy = function(fn) {
    //creates an empty object that will hold all grouped results
    const grouped={};
    for(const item of this){
        //get group key by calling fn on item
        const key=fn(item);
        //initilise group key if it doesn't exists
        if(!grouped[key]){
            grouped[key]=[];
        }
        //add items to the group
        grouped[key].push(item);
    }
    return grouped;

};

/**
 * [1,2,3].groupBy(String) // {"1":[1],"2":[2],"3":[3]}
 */