const readline = require('readline').createInterface({
    input: process.stdin,
    output: process.stdout
});

let lines = [];
readline.on('line', (input) => lines.push(input)).on('close', () => {
    let index = 0;

    while (true) {
        let repeat = parseInt(lines[index++]);
        if (repeat === 0) break;

        let [xlog, ylog] = lines[index++].split(' ').map(Number);

        for (let i = 0; i < repeat; i++) {
            let [xcurrent, ycurrent] = lines[index++].split(' ').map(Number);

            if (xcurrent === xlog || ycurrent === ylog) console.log("divisa");
            else if (xcurrent > xlog && ycurrent > ylog) console.log("NE");
            else if (xcurrent < xlog && ycurrent > ylog) console.log("NO");
            else if (xcurrent < xlog && ycurrent < ylog) console.log("SO");
            else console.log("SE");
        }
    }
});
