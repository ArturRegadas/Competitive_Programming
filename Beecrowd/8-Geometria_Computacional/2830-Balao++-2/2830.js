const readline = require("readline").createInterface({
    input: process.stdin,
    output: process.stdout
});

readline.question("", input => {
    const [radix, gas] = input.split(" ").map(Number);
    const area = (4.0 / 3.0) * (3.1415 * (radix ** 3));
    console.log(Math.floor(gas / area));

});
