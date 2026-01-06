// 문제 접근

// 1. 입력 받기
// 2. 끝나는 시간 역순 정렬 && 시작하는 시간 역순 정렬
// 3. 되는 시간 순으로 리스트에 삽입
// 4. 길이 출력

import java.util.*

fun main(args: Array<String>) {
    // 1.
    val N: Int = readLine()!!.toInt()
    
    val times = Array(N) { Array<Int>(3) { 0 } }
    for (i in 0..N-1) {
      var eachTime = readLine()!!.split(" ")
      times[i][0] = eachTime[0].toInt()
      times[i][1] = eachTime[1].toInt()
      times[i][2] = times[i][1]-times[i][0]
    }
    
    times.sortByDescending { it[1] }
    times.sortByDescending { it[0] }
    
    // var result = 
    for (time in times) {
      println("${time[0]} ${time[1]} ${time[2]}")
    }
}
