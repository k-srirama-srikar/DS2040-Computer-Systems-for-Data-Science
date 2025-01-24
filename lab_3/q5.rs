use std::mem;

fn compare_floats(a:f32, b:f32)->i32{
    // unsure about the answer tho
    let a_bits:u32 = unsafe{mem::transmute(a)};
    let b_bits:u32 = unsafe{mem::transmute(b)};
    if a_bits < b_bits {
        -1
    } else if a_bits > b_bits {
        1
    } else {
        0
    }
}

fn main() {
    println!("Compare 0.5 and 1.0: {}", compare_floats(0.5, 1.0));
    println!("Compare -1.0 and 1.0: {}", compare_floats(-1.0, 1.0));
    println!("Compare NaN and Inf: {}", compare_floats(f32::NAN, f32::INFINITY));
}