fn main(){
    let mut a = 10;
    let mut b = 20;
    let a_ref = &mut a;
    let b_ref = &mut b;
    let temp = *a_ref;
    *a_ref = *b_ref;
    *b_ref = temp;
    println!("a = {}, b = {}", a, b);
}