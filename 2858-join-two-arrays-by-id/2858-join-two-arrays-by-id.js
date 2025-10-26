/**
 * @param {Array} arr1
 * @param {Array} arr2
 * @return {Array}
 */
var join = function(arr1, arr2) {
    //create a map to store key-value pair
    const map={};
    //insert all objects from arr1 in to the map
    for(const obj of arr1){
        map[obj.id]=obj;
    }
    //process arr2 and add objects into the map
    //for common objects, merge them st properties of arr2 override properties of arr1
    for(const obj of arr2){
        if(map[obj.id]){
           map[obj.id]={...map[obj.id], ...obj};
        }
        else{
            map[obj.id]=obj;
        }
    }
    //convert the merged map back into the array
    return Object.values(map).sort((a,b)=>a.id-b.id);


};