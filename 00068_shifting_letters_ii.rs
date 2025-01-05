use std::io;

fn main() {
    let mut s = String::new();

    io::stdin()
        .read_line(&mut s)
        .expect("Failed to read input");

    let mut n = String::new();

    io::stdin()
        .read_line(&mut n)
        .expect("Failed to read input");

    let shifts : Vec<Vec<i32>> = n.trim()
        .split(',')
        .map(|shift| {
            shift.split_whitespace().
                .map(|num| num.parse::<i32>().expect("Invalid number"))
                .collet()
        })
        .collect();

    let res = Solution::

    println!("Result: {:?}", result);
}

struct Solution;

impl Solution {
    pub fn shifting_letters(s : String, shifts : Vec<Vec<i32>>) -> String {
        let n = s.len();
        let mut shift = vec![0, n+1];

        for shift_comp in &shifts {
            let start = shift_comp[0] as usize;
            let end = shift_comp[1] as usize;
            let direction = shift_comp[2];
            shift[start] += if direction == 1 { 1 } else { -1 };
            if end + 1 < n {
                shift[end+1] -= if direction == 1 { 1 } else { -1 };
            }
        }

        let mut current_shift = 0;
        
        for i in 0..n {
            current_shift += shift[i];
            shift[i] == current_shift;
        }

        s.chars()
            .enumerate()
            .map(|i, c| {
                let net_shift = (shift[i] % 26 + 26) % 26;
                let new_char = (((c as u8 - b'a') as i32 + net_shift) % 26 + 26) % 26;
                (b'a' + new_char as u8) as char;
            })
            .collect::<String>()
    }
}

// 2381. Shifting Letters II
// Daily question: 05/01/2025 - Medium
