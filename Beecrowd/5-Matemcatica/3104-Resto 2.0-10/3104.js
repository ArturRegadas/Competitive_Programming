var input = require('fs').readFileSync('/dev/stdin', 'utf8');
var l = input.split('\n').filter(line => line.trim() !== '');


let i = 0;
while(i<l.length){
    let A = l[i];
    i++;
    let B = parseInt(l[i]);
    i++
    let resto = 0;
    for(let c of A){
        resto = (resto * 10 + parseInt(c)) % B;
    }
    console.log(resto);
}