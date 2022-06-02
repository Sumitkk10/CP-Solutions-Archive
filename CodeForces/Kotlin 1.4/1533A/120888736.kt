private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readDouble() = readLn().toDouble() // single double
private fun readLong() = readLn().toLong() // single long
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles
private fun readLongs() = readStrings().map { it.toLong() } // list of longs

fun main(){
     var t = readLong()
     var ct = 0
     while(ct < t){
          var(n, k) = readInts()
          var it = 0
          var mx = 0
          while(it < n){
               var(l, r) = readInts()
               if(l <= k){
                    if(r - k + 1 > mx)
                         mx = (r - k + 1)
               }
               ++it
          }
          println(mx)
          ++ct;
     }
}
