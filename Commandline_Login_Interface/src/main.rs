use std::{io, num::ParseIntError, i32};

struct Account 
{
    id: i32,
    username: String,
    password: String,
    first_name: String,
    last_name: String
}

fn main() {
    let answer = startup();

    


}

fn startup() -> Result<i32, ParseIntError>  {
    let mut input = String::new();

    println!("Welcome!");
    println!("If you would like to sign up enter 1.");
    println!("If you would like to login enter 2");
    println!("If you would like to exit enter 0");
    io::stdin().read_line(&mut input).expect("Failed to read from STDIN");

    let result = input.trim().parse::<i32>();

    result
}
