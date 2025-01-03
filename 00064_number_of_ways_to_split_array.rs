use std::io;

fn main() {
    let mut s = String::new();

    io::stdin()
        .read_line(&mut s)
        .expect("Failed to read input");

    let nums : Vec<String> = s.trim().split_whitespace().map(|num| num.parse::<i32>().expect("Invalid number")).collect();

    let res = Solution::ways_to_split_array(nums);

    println!("Result: {:?}", result);
}

struct Solution

impl Solution {
    pub fn ways_to_split_array(nums: Vec<i32>) -> i32 {
        let total_sum : i64 = nums.iter().map(|&x| x as i64).sum();
        let mut left_sum : i64 = 0;
        let mut ans : i32 = 0;

        for i in 0..nums.len() - 1 {
            left_sum += nums[i] as i64;
            let right_sum = total_sum - left_sum;

            if left_sum >= right_sum {
                ans += 1;
            }
        } 
        
        ans
    }
}

// 2270. Number of Ways to Split Array
// Daily question: 03/01/2025 - Medium