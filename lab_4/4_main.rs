extern "C"{
    // C calling convention is platform specific
    // and is used for 64 bit systems
    fn asm_func(a:i64, b:i64)->i64;
}

fn main() {
    let a: i64 = 5;
    let b: i64 = 3;

    // Call the assembly function and get the result
    unsafe {
        let result = asm_func(a, b);
        println!("Result from assembly function: {}", result);
    }
}