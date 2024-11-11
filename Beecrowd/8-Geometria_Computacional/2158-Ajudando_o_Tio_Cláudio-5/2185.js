let i = 1;
const readline = require('readline').createInterface({
    input: process.stdin,
    output: process.stdout
});

function processInput() {
    readline.question('', (input) => {
        try {
            const [fp, fh] = input.split(' ').map(Number);
            const edge = (fp * 5 + fh * 6) / 2;
            const vertex = 2 - (fp + fh) + edge;
            console.log(`Molecula #${i}.:.`);
            console.log(`Possui ${Math.floor(vertex)} atomos e ${Math.floor(edge)} ligacoes\n`);
            i++;
            processInput();
        } catch {
            readline.close();
        }
    });
}

processInput();
