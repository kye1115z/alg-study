#!/usr/bin/env kotlin

fun main() {
    val N = readLine()!!.toInt()

    // N개의 정수 A[1], A[2] ... A[N]
    val A = readLine()!!.split(" ").map { it.toInt() }

    val M = readLine()!!.toInt()
    val arr = readLine()!!.split(" ").map { it.toInt() }

    val sb = StringBuilder()

    val sorted = A.sorted()

    for( num in arr ) {
        // num이 존재하면 1 아니면 0 출력
        var left = 0
        var right = N-1

        var isExist = false // 값이 존재하는지 확인

        while(left <= right) {
            val mid = (left + right) / 2

            if(sorted[mid] == num) {
                isExist = true
                break
            } else if(sorted[mid] >= num) {
                right = mid - 1
            } else  {
                left = mid + 1
            }
        }

        if(isExist) {
            sb.append(1).append("\n")
        } else {
            sb.append(0).append("\n")
        }
    }

    println(sb)
}