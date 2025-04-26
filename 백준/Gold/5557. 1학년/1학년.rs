use std::io;

fn main() {

    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let n: usize = input.trim().parse().unwrap();

    input.clear();

    io::stdin().read_line(&mut input).unwrap();
    let numbers: Vec<u32> = input.trim().split_whitespace()
        .map(|s| s.parse().unwrap())
        .collect();

    
    let mut dp = vec![vec![0u64; 21]; n-1];

    dp[0][numbers[0] as usize] = 1;

    for i in 1..n-1 {
        for sum in 0..=20u32 {
            let sum_usize = sum as usize;
            if dp[i-1][sum_usize] > 0 {
                let add = sum + numbers[i];
                if add <= 20 {
                    dp[i][add as usize] += dp[i-1][sum_usize];
                }
                if sum >= numbers[i] {
                    let sub = sum - numbers[i];
                    dp[i][sub as usize] += dp[i-1][sum_usize];
                }
            }
        }
    }



    println!("{}", dp[n-2][numbers[n-1] as usize]);
    


    
}
