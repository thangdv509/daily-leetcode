use std::io;

fn main() {
    let mut s = String::new();

    io::stdin()
        .read_line(&mut s)
        .expect("Failed to read input");

    let words : Vec<String> = s.trim().split_whitespace().map(|s| s.to_string()).collect();

    let mut q = String::new();

    io::stdin()
        .read_line(&mut q)
        .expect("Failed to read input");

    let queries : Vec<Vec<i32>> = q.trim()
        .split(',')
        .map(|pair| {
            pair.split_whitespace().
                .map(|num| num.parse::<i32>().expect("Invalid number"))
                .collet()
        })
        .collect();

    let res = Solution::vowel_strings(words, queries);

    println!("Result: {:?}", result);
}

struct Solution;

impl Solution {
    pub fn is_vowel(s: char) -> bool {
        matches!(s, 'a' | 'e' | 'i' | 'o' | 'u')
    }

    pub fn vowel_strings(words: Vec<String>, queries: Vec<Vec<i32>>) -> Vec<i32> {
        let m = words.len();
        let mut prefixsum = vec![0; m];
        let mut cnt = 0;

        for (i, word) in words.iter().enumerate() {
            if Self::is_vowel(word.chars().next().unwrap()) && Self::is_vowel(word.chars().last().unwrap()) {
                cnt += 1;
            }
            prefixsum[i] = cnt;
        }

        queries.iter()
            .map(|query| {
                let l = query[0] - 1;
                let r = query[1];
                prefixsum[r as usize] - if l >= 0 { prefixsum[l as usize] } else { 0 }
            })
            .collect();
    }
}

// 2559. Count Vowel Strings in Ranges
// Daily question: 02/01/2025 - Medium
