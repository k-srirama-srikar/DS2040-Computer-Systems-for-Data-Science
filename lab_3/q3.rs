const INT_MAX: i32 = i32::MAX;
const INT_MIN: i32 = i32::MIN;

fn saturating_add(a:i32, b:i32) -> i32{
    if a>0 && b>0 && a>INT_MAX-b{
        return INT_MAX;
    }
    if a<0 && b<0 && a<INT_MIN-b{
        return INT_MIN;
    }
    a+b
}


fn saturating_sub(a:i32, b:i32) -> i32{
    if a>0 && b<0 && a>INT_MAX+b{
        return INT_MAX;
    }
    if a<0 && b>0 && a<INT_MIN+b{
        return INT_MIN;
    }
    a-b
}


fn main() {
    // Test saturating addition and subtraction
    println!("Saturating Add (INT_MAX, 1): {}", saturating_add(INT_MAX, 1)); // should return INT_MAX
    println!("Saturating Sub (INT_MIN, 1): {}", saturating_sub(INT_MIN, 1)); // should return INT_MIN
    println!("Saturating Add (10, 20): {}", saturating_add(10, 20)); // should return 30
    println!("Saturating Sub (10, 20): {}", saturating_sub(10, 20)); // should return -10
}