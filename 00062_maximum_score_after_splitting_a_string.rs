use std::io;

fn main() {
    let mut s = String::new();

    io::stdin()
        .read_line(&mut s)
        .expect("Failed to read input");
    
    let s = s.trim().to_string();

    let result = Solution::max_score(s);
    println!("Maximum score: {}", result);
}

struct Solution;

impl Solution {
    pub fn max_score(s: String) -> i32 {
        let mut one_count = 0;
        let mut zero_count = if s.as_bytes()[0] == b'0' {1} else {0};
        let mut maximum_score = 0;

        for &ch in s.as_bytes().iter().skip(1) {
            if ch == b'1' {
                one_count += 1;
            }
        }

        let mut i = 1;
        let n = s.len();

        for &ch in s.as_bytes().iter().skip(1) {
            if i == n - 1 {
                continue;
            }

            maximum_score = maximum_score.max(one_count + zero_count);

            if ch == b'1' {
                one_count -= 1;
            } else {
                zero_count += 1;
            }
            i += 1;
        }

        maximum_score = maximum_score.max(one_count + zero_count);

        maximum_score

    }
}

// 1422. Maximum Score After Splitting a String
// Daily question: 01/01/2025 - Easy 
