function match(strings,queries){
    let res = []
    let count = 0;
    queries.forEach((q,i)=>{
        strings.forEach((s,i)=>{
            q===s? count++ : null;
        })
        res.push(count)
        count=0;
    })

    return res;

}

console.log(match(['a','b','a','c','d'],['a','b','e']))