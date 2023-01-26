fn quote() {
    let x = 5;
    let y = &x;
    assert_eq!(5, x);
    assert_eq!(5, *y);
}

fn no_mut_quote() {
    // 可变引用与不可变引用不能同时存在
    let s1 = String::from("hello");
    let s2 = &s1;
    println!("s1:{}, s2:{}", s1, *s2);
}

fn mut_quote() {
    // 可变引用同时只能存在一个
    let mut s1 = String::from("hello");
    let s2 = &mut s1;
    s2.push_str(", world!");
    println!("s2:{}", *s2);
}
fn nll() {
    // Non-Lexical Lifetimes(NLL)
    let mut s = String::from("hello, ");

    let r1 = &mut s;
    r1.push_str("world");
    let r2 = &mut s;
    r2.push_str("!");

    // println!("s:{}", s);
    // println!("r1:{}", r1);
    println!("r2:{}", r2);
}

fn main() {
    quote();

    no_mut_quote();
    mut_quote();

    nll();
}
