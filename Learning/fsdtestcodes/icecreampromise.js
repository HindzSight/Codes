function cleanRoom(isClean){
    return new Promise((resolve,reject)=>{
        setTimeout(()=>{
            const isClean = Math.random() < 0.5;
            if(isClean){
                resolve("ROOM IS CLEAN");
            }else{
                reject("ROOM IS DIRTY");
            }
        },2000);
    });
}

cleanRoom()
    .then((result)=>{
        console.log(result);
        console.log("ICE CREAM");
    })
    .catch((err)=>{
        console.log(err);
        console.log("NO ICE CREAM! SCREAM");
    });