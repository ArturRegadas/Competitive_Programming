var input = require('fs').readFileSync('/dev/stdin', 'utf8');
var lines = input.trim().split('\n');
let i = 0;
while(i<lines.length){
    let n = lines[i];i++;
    let nums = lines[i].trim().split(' ').map(x => parseInt(x));i++;
    let sum = nums.reduce((a, b) => a + b, 0); //sum
    let mid = parseInt(sum/2);
    let dp = Array(150001).fill(false);
    dp[0] = true;
    for (let i of nums){
        for(let j = mid; j>= i;j--){
            dp[j] |= dp[j-i];
        }
    }
    for(let i = mid; i>=0;i--){
        if(dp[i]){
            console.log(sum-2*i);
            break;
        }
    }
    
}