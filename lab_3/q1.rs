fn parity(n: u32) -> u32{
    let mut n = n;
    let mut parity =0;
    while n!=0{
        parity ^= n&1;
        n>>=1;
    }
    parity
}

fn main(){
    let numbers = [0x80000000, 0xFFFFFFFF, 0x00000001];

    for &num in &numbers{
        println!("Number: {:x}", num);
        println!("Binary: {:032b}", num);
        println!("Parity: {}", parity(num));
    }

}