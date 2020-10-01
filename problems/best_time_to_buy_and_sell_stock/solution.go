func maxProfit(prices []int) int {
    if len(prices)<2{
        return 0 
    }
    var b = prices[0]
    var s = 0
    for _,i:=range prices{
        if i < b{
            b = i
        }else if i > b{
            s = max(s,i-b)
        }
    }
    return s 
}

func max(a int, b int) int{
    if a > b{
        return a
    }
    return b
}
