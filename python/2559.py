n = int(input())
m = int(input())
nums = list(map(int, input().split()))

nums.sort()
left, right = 0, len(nums) - 1
ret = 0

while left < right:
    sum = nums[left] + nums[right]

    if sum < m:
        left+=1
    elif sum > m:
        right-=1
    else:
        ret+=1
        left+=1
print(ret)