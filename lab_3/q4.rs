fn count_leading_zeros(x: u32) -> u32 {
    x.leading_zeros()
}

fn count_tailing_zeros(x: u32) -> u32 {
    x.trailing_zeros()
}

fn main() {
    let numbers = [0x00000001, 0x80000000, 0x000000F0];
    
    for &num in &numbers {
        println!("Number: {:032b}", num);
        println!("Leading zeros: {}", count_leading_zeros(num));
        println!("Tailing zeros: {}", count_tailing_zeros(num));
    }
}
