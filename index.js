const express = require('express');
const app =express();

var exec= require('child_process').exec,child;
const fs = require("fs");


 



app.post('/', (req,res,next)=>{
    const content = req.body.content;
    fs.writeFile('Analizador Lexicográfico/codigo.guat',content, (error) =>{
        console.log(error);
        child=exec('./Analizador Lexicográfico/compile.sh', (error,stdout,stder)=>{
            return res.status(200).json({
                ok: true
            });
        });
    });
    
    fs.readFile('Analizador Lexicográfico/algo.txt','utf8', (err, data) => {
        if (err) {
            console.error(err)
            return
        }
        console.log(data);
    });

});

app.listen(5000,()=>{
    console.log('Eschucha el server');
});
