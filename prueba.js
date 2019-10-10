const express = require('express');
const app =express();

var exec= require('child_process').exec,child;
const fs = require("fs");


 



app.get('/', (req,res,next)=>{
    //const content = req.body.content;
    fs.readFile('Analizador Lexicográfico/prueba.txt', (err, data) => {
        if (err) {
          console.error(err)
          return
        }
        console.log(JSON.parse(data));
    });

});

app.listen(5000,()=>{
    console.log('Eschucha el server');
    
    
});