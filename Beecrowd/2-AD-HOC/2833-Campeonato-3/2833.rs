//O(n log n), recursive
use std::io;

fn find(arr: &[i32], target:i32) -> bool{
    for i in arr{
        if(*i == target){
            return true;
        }
    }
    return false;
}

fn solution(arr: &[i32], l:i32, r:i32, values: (i32, i32), depth:i32) -> i32{
    let mut m:i32 = (l+r)/2;
    let in1 = find(&arr[l as usize ..m as usize], values.0);
    let in2 = find(&arr[l as usize..m as usize], values.1);

    if(in1 == in2){
        if(in1){
            return solution(&arr, l, m, values, depth+1);
        }
        return solution(&arr, m, r, values, depth+1);
    }
    return depth;
    
}

fn main(){
    let mut keys = Vec::new();
    let mut inp = String::new();
    io::stdin().read_line(&mut inp).unwrap();

    let mut it = inp.split(' ');

    for i in 0..16{
        let mut v:i32 = it.next().unwrap().trim().parse().unwrap();
        keys.push(v);
    }

    let ku = 1;
    let lu = 9;

    let depth = solution(&keys, 0, 16, (ku, lu), 0);
    if(depth == 0){
        println!("final");
    }
    else if(depth == 1){
        println!("semifinal");
    }
    else if(depth == 2){
        println!("quartas");
    }
    else{
        println!("oitavas");
    }

}