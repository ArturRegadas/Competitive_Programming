const fs = require('fs');
const input = fs.readFileSync('/dev/stdin', 'utf8').trim().split('\n');

function splitString(a) {
    const ans = [];
    let current = "";
    let was = true;

    for (const i of a) {
        if (i !== ' ') {
            current += i;
            was = false;
        } else {
            if (!was) {
                ans.push(parseInt(current));
                was = true;
            }
            current = "";
        }
    }
    ans.push(parseInt(current));
    return ans;
}

let i = 0;
while (i < input.length) {
    const n = parseInt(input[i].trim()); i++;
    let nums = splitString(input[i].trim()); i++;

    while (nums.length < n) {
        nums.push(...splitString(input[i].trim()));
        i++;
    }

    let l = 0, r = n - 1;
    let La = 0, Ra = 0;

    while (l < r) {
        if (La + nums[l] < Ra + nums[r]) {
            La += nums[l];
            l++;
        } else {
            Ra += nums[r];
            r--;
        }
    }

    if (Ra < La) Ra += nums[r];
    else La += nums[l];

    console.log(Math.abs(La - Ra));
}
