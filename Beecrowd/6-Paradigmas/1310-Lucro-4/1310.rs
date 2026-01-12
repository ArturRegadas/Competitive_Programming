// O(n²) solution
use std::io;

fn sum_ranges(arr: &[i32], l:usize, r:usize) -> i32{
    let mut ans = 0;
    for i in l..=r{
        ans += arr[i];
    }
    ans
}

fn run() -> Result<(), ()> {
    let mut inp = String::new();

    if io::stdin().read_line(&mut inp).unwrap() == 0 {
        return Err(());
    }
    let n: usize = inp.trim().parse().unwrap();

    inp.clear();
    io::stdin().read_line(&mut inp).unwrap();
    let cost: i32 = inp.trim().parse().unwrap();

    let mut nuns = vec![0; n];

    for i in 0..n {
        inp.clear();
        io::stdin().read_line(&mut inp).unwrap();
        nuns[i] = inp.trim().parse().unwrap();
    }

    let mut ans = 0;
    for i in 0..n {
        for j in (i)..n {
            let gain = sum_ranges(&nuns, i, j) - (j - i + 1) as i32 * cost;
            ans = ans.max(gain);
        }
    }

    println!("{}", ans);
    Ok(())
}


fn main(){
    loop {
        match run(){
            Ok(_) => continue,
            Err(_) => break,
        }
    }  
}