#![feature(asm)] // Enable the inline assembly feature (unstable)
// so... in my opinion c is better for inline assembly
fn main() {
    let mut a: i64 = 5; // Initialize a
    let b: i64 = 3;     // Initialize b

    unsafe {
        // Inline assembly block
        asm!(
            "add {0}, {1}",  // Assembly instruction (AT&T syntax)
            inout(reg) a => a, // Input-output operand: a is both input and output
            in(reg) b,         // Input operand: b is only input
        );
    }

    println!("Result of inline addition: {}", a); // Print the result
}
