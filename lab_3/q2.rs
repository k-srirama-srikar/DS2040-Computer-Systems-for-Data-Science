use std::mem;

fn extract_float_info(val: f32){
    let bits: u32 = unsafe {mem::transmute(val)};
    let sign = (bits>>31)&1;
    let exponent = (bits>>23)&0xFF;
    let mantissa = bits&0x7FFFFF;

    println!("Sign: {}", sign);
    println!("Exponent: {}", exponent);
    println!("Mantissa: {:#X}", mantissa); 
}


fn main(){
    let input: f32 = 1.23;
    extract_float_info(input);
}