use std::arch::asm; // Import the inline assembly macro

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
