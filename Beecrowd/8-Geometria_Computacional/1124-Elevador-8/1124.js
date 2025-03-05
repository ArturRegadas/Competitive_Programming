var input = require('fs').readFileSync('/dev/stdin', 'utf8');
var lines = input.trim().split('\n');

for (let line of lines){
    var [l, c, r1, r2] = line.split(' ').map(x => parseInt(x));
    if(l==0 && c ==0 && r1 ==0 && r2 ==0)break;
    if(2*r1>l || 2*r1>c || 2*r2>l || 2*r2>c){
        console.log("N");
        continue
    }
    if(Math.sqrt(Math.pow(l-r1-r2, 2)+Math.pow(c-r2-r1, 2)) >= r1+r2){
        console.log("S");
        continue;
    }
    console.log("N");
}
