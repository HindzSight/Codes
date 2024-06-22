async function performtransact(){
    try{
        await transact("WHOLESALER").then((res)=>console.log(res));
        
        await transact("RETAILER").then((res)=>console.log(res));

        await transact("CUSTOMER").then((res)=>console.log(res));
    }catch(err){
        console.log(err);
    }
}

async function transact(title){
    return new Promise((resolve,reject) => {
        let rand = Math.floor(Math.random() * 100);
        if(title.toUpperCase() === title){
            setTimeout(()=>{resolve(`${title} transacts`);},rand);
        }else{
            reject("Title not in Upper Case");
        }
    });
}
console.time();
performtransact();
console.timeLog();