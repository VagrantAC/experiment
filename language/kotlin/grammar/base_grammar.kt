package main

fun helloFunction(name: String) = "Hello $name !"

fun main(args : Array<String>) {
  val i: Int = 8
  println(i)

  val l: Long = 100000000000000000
  println(l)

  var d: Double? = null
  println(d)
  d = 10.0
  println(d)

  val s: String = "world"
  println(helloFunction(s))

  println(helloFunction(name = "world"))

  val message = if (i > 10) "Big" else "Small"
  println(message)

  val array = arrayOf(1, 2, 3)
  for (index in array) {
    print(index)
    print("   ")
  }
  println()

  for (index in 1..3) {
    print(index)
    print("   ")
  }
  println()
}
