use std::io;

fn fib(n: usize) -> Vec<i64> {
    let mut f = vec![1, 2]; 
    for i in 2..n {
        f.push(f[i - 1] + f[i - 2]);
    }
    f
}

fn main() {
    let mut inp = String::new();
    io::stdin().read_line(&mut inp).unwrap();
    let t: usize = inp.trim().parse().unwrap();

    let fibs = fib(30);

    for _ in 0..t {
        inp.clear();
        io::stdin().read_line(&mut inp).unwrap();
        let mut x: i64 = inp.trim().parse().unwrap();

        let mut ans: i64 = 0;

    
        let mut used = vec![0; fibs.len()];

        for i in (0..fibs.len()).rev() {
            if fibs[i] <= x {
                x -= fibs[i];
                used[i] = 1;
            }
        }

    
        for i in 1..used.len() {
            if used[i] == 1 {
                ans += fibs[i - 1];
            }
        }

        println!("{}", ans);
    }
}
