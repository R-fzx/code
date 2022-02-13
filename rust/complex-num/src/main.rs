use num::complex::Complex;

fn main() {
  let a = Complex { re: 2.1, im: -1.2 };
  let b = Complex::new(11.1, 22.2);
  let r = a + b;

  println!("{} + {}i", r.re, r.im);
}