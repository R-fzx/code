#[warn(non_snake_case)]
#[warn(unused_must_use)]
fn main() {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s);
    let a: i32 = s.parse().unwrap();
    println!("{}", a);
    println!("{}", s);
}