fn transfer_ownership() {
    let s1 = String::from("hello");
    let s2 = s1;
    let s3 = s2;
    println!("{}, world!", s3);
}

fn deep_clone() {
    let s1 = String::from("hello1");
    let s2 = s1.clone();
    println!("s1:{}, s2:{}", s1, s2);
}

fn shallow_clone() {
    let x = 5;
    let y = x;
    println!("x:{}, y:{}", x, y);
}

fn main() {
    transfer_ownership();

    // 对于拷贝可以理解为每次只会拷贝栈上的数据
    deep_clone();

    // 栈上的数据(基础数据类型)会自动完成浅拷贝
    shallow_clone();
}
