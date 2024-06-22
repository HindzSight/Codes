const add = (function(){
    let counter = 0;
    return function(){
        counter += 1;
        console.log("Counter : "+ counter);
        return counter;
    }
})();

console.log("Call 1 : ");add();
console.log("Call 2 : ");add();
console.log("Call 3 : ");add();
console.log(add());