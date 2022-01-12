use std::ops::Index;

fn main() {
  println!("{}, {}, {}", find("RUNOOB", 'O'), find("wsfxk", 'x'), find("podfdfcwec", 'd'))
}

fn find(s: &str, c: char) -> Index<usize> {
  let mut i: Index<usize> = 0;
  return loop {
    if s[i] == c {
      break i;
    }
    i += 1;
  };
}
