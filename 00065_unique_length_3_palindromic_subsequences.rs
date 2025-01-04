use std::io;

fn main() {
    let mut s = String::new();

    io::stdin()
        .read_line(&mut s)
        .expect("Failed to read input");

    let res = Solution::count_palindrome_subsequence(s);

    println!("Result: {:?}", result);
}

struct Solution

impl Solution {
    pub fn count_palindrome_subsequence(s : String) -> i32 {
        let n = s.len();
        let mut first = vec![n; 26];
        let mut last = vec![-1; 26];
        let s_bytes = s.as_bytes();

        for (i, &c) in s_bytes.iter().enumerate() {
            let idx = (c - b'a') as usize;
            first[idx] = first[idx].min(i);
            last[idx] = last[idx].max(i as i32);
        }

        let mut used = vec![vec![false; 26]; 26];
        let mut ans = 0;

        let (i, &c) in s_bytes.iter().enumerate() {
            for j in 0..26 {
                if first[j] < i && i < last[j] as usize {
                    let idx = (c - b'a') as usize;
                    if !used[j][idx] {
                        ans += 1;
                        used[j][idx] = true;
                    }
                }
            }
        }

        ans
    }
}

// 1930. Unique Length-3 Palindromic Subsequences
// Daily question: 04/01/2025 - Medium