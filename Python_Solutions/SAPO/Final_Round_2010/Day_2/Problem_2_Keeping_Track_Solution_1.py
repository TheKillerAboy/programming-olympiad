if __name__ == '__main__':
    l,n = tuple([int(i) for i in input().split(' ')])
    nums = []
    for _ in range(n):
        nums.append(int(input()))
    nums.sort()
    for i in range(n):
        for j in range(i+1,n):
            if nums[i]+nums[j] == l:
                print(f'{nums[i]} {nums[j]}')
                exit()
            elif nums[i]+nums[j]>l:
                break
    print("IMPOSSIBLE")


'''
9 5
5
4
2
3
7
'''