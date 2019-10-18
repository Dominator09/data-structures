
(function(){
    str1 = "rararraraar";
    str2 = "rar";
    let j = 0;
    let found = 0;
    let i = 0;
    let k = 0;
    let index = [];
    while(i < str1.length || k != str1.length ){
        console.log("$$$$$$$$$$$",i,j,k,str1[k],str2[j],found);
        if(str1[k] === str2[j]){
            j++;
            k++;
        }
        else if(j > 0 && str1[k] != str2[j]){
            j = 0;
        }
        else{
            k++;
            j = 0;
        }
        if(j === str2.length){
            found++;
            index.push(k-str2.length );
            j = 0;
        }
        i++;
    }
    console.log("########",found,index);
})();
