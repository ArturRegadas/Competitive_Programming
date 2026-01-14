use std::io;

fn sum(arr: &[i64], size:i64) -> i64{
    let mut ans = 0;
    for i in 0..size{
        ans += arr[i as usize];
    }
    ans
}

fn main(){
    const MAXN:i64 = 1000010;

    let mut inp = String::new();
    io::stdin().read_line(&mut inp).unwrap();

    let n:i64 = inp.trim().parse().unwrap();
    
    let mut vec = Vec::new();

    inp.clear();
    io::stdin().read_line(&mut inp).unwrap();

    let mut it = inp.split(' ');
    for i in 0..n{
        let v:i64 = it.next().unwrap().trim().parse().unwrap();
        vec.push(v);
    }

    let total = sum(&vec, n);

    let mut idx = 0;
    let mut anm = 0;
    let mut pro = vec![0i64; n as usize];
    while (idx >= 0 && idx < n){
        let mut aux = 0;
        pro[idx as usize] = 1;
        if(vec[idx as usize]>0){
            vec[idx as usize] -=1;
            anm +=1;
            aux = 1;
        }
        if((vec[idx as usize]+aux)%2 == 0){
            idx -=1;
        }
        else{
            idx +=1;
        }
    }
    println!("{} {}", sum(&pro, n), total-anm);

}
