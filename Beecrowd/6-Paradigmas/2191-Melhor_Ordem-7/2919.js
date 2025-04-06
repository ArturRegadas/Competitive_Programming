const fs = require('fs');
const input = fs.readFileSync(0, 'utf8').split('\n');

function lowerBound(arr, target) {
    let l = 0, r = arr.length;
    while (l < r) {
        let mid = (l + r) >> 1;
        if (arr[mid] < target) l = mid + 1;
        else r = mid;
    }
    return l;
}

function LIS(arr) {
    const lis = [];
    for (let x of arr) {
        const i = lowerBound(lis, x);
        if (i === lis.length) lis.push(x);
        else lis[i] = x;
    }
    return lis.length;
}

let i = 0;
while (i < input.length) {
    while (i < input.length && input[i].trim() === '') i++; // ignora linhas vazias
    if (i >= input.length) break;

    const n = parseInt(input[i++]);
    let nums = [];

    while (nums.length < n && i < input.length) {
        nums.push(...input[i++].trim().split(/\s+/).map(Number));
    }

    console.log(LIS(nums));
}
