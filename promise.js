

function out(){
    let x = new Promise(function(resolve,reject){
        setTimeout(function(){
            console.log("this time ")
            resolve();
        },1000);
    }).then(function(){
        console.log("that is");
        return 1;
    }).then(function(result){
        console.log("RESULT-->",result);
    });

    console.log("second");
    
}
out();


