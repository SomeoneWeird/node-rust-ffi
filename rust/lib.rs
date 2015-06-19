
#![crate_type = "dylib"]
#![crate_name = "rary"]

#[no_mangle]
pub extern "C" fn add(one: i32, two: i32) -> i32 {
  one + two
}
