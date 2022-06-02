private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int

fun main(args: Array<String>){
     var t = readInt()
     var ct = 0
     while(ct < t){
          var s = readLn()
          var i = 0
          var f = 0
          var g = 0
          var r = 0
          var n = s.length - 1
          for(i in 0..n){
            if(s[i] == '<') g = g + 1
            else if(s[i] == '>') f = f + 1
            else r = r + 1
          }
          if(g > 0 && f > 0) println('?')
          else if(g > 0) println('<')
          else if(f > 0) println('>')
          else println('=')
          ct = ct + 1
     }
}