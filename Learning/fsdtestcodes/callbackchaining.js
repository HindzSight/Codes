let err;
function transact(title,callback){
    let rand = Math.floor(Math.random() * 100);
    if(title.toUpperCase() != title){
        err = new Error("Uppercase Error");
    }
    setTimeout(()=>{callback(err)},rand);
}

transact("DISTRIBUTOR",(err)=>{
    if(err){
        console.log(err)
    }else{
        console.log("DISTRIBUTOR has done transaction");
        transact("WHOLESALER",(err)=>{
            if(err){
                console.log(err)
            }else{
                console.log("WHOLESALER has done transaction");
                transact("RETAILER",(err)=>{
                    if(err){
                        console.log(err);
                    }else{
                        console.log("RETAILER has done transaction");
                    }
                });
            }
        });
    }
});