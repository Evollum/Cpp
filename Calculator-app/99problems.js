// 99problems.js

const readline = require("readline");

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

// Ask the user to enter a number
rl.question("Enter a number: ", (input) => {
  let N = parseInt(input);
  let result;

  if (N < 99) {
    result = 99;
  } else if (N === 10000) {
    result = 9999;
  } else {
    // Find the nearest number ending in 99, above or equal to N
    let down = Math.floor(N / 100) * 100 + 99;
    if (down > N) down -= 100;
    let up = down + 100;
    // Choose the closest, prefer the bigger one in a tie
    if (Math.abs(N - down) < Math.abs(up - N)) {
      result = down;
    } else {
      result = up;
    }
  }

  console.log(`For N = ${N}, the result is: ${result}`);
  rl.close();
});
