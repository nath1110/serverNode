const express = require('express');
const app =express();

var exec= require('child_process').exec,child;
const fs = require("fs");

var fs = require('fs');
 



app.post("/", (req,res,next)=>{
    const content = req.body.content;
    fs.writeFile('Analizador Lexicográfico/prueba.guat', content, (error) =>{
        console.log(error);
        child=exec('./Analizador Lexicográfico/compile.sh', (error,stdout,stder)=>{
            return res.status(200).json({
                ok: true,
                returnedCode:stdout,
            });
        });
    });

});


