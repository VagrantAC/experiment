fn main() {
    let mut x = 5;
    println!("The value of x is: {}", x);

    x = 6;
    println!("The value of x is: {}", x);

    {
        let x = x * 2;
        println!("The value of x is: {}", x);
    }
    println!("The value of x is: {}", x);

    {
        x = x * 2;
        println!("The value of x is: {}", x);
    }
    println!("The value of x is: {}", x);

    let _a = 1;
    let b = 1; // unsed variable: `b`   `#![warn(unsed_variables)]` on by default
}
