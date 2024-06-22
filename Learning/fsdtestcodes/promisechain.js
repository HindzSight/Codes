function transact(title){
    return new Promise((resolve,reject)=>{
        // console.log(title)
        if(title.toUpperCase() == title){
            resolve(`${title} transacts`);
        }else{
            reject("Title not in Upper Case");
        }
    })
}

transact("WHOLESALER")
.then((result)=>{
    console.log(result)
    return transact("RETAILER")
})
.then((result)=>{
    console.log(result)
    return transact("CUSTOMER")
})
.then((result)=>{
    console.log(result)
})
.catch((result)=>{
    console.log(result)
})