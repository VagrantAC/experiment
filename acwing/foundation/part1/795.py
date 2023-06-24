if __name__ == "__main__":
    _, m = map(int, input().split(" "))

    sum = []
    count = 0
    for array in input().split(" "):
        count += int(array);
        sum.append(count)
    
    for _ in range(0, int(m)):
        l, r = map(int, input().split(" "))
        l = l - 1
        r = r - 1
        if l != 0:
            print(int(sum[r]) - int(sum[l-1]))
        else:
            print(int(sum[r]))
