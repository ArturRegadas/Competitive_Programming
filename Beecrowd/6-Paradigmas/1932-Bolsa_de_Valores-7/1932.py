s, t = map(int, input().split(' '))
day = list(map(int, input().split(' ')))
ant = current = day[0]
ans = 0
for i in range(1, s):
    if (current > day[i] and current-day[i]>=t) or ant>day[i]:
        ans=max(ans, ans+ current-ant-t)
        current = ant = day[i]
        
    if(day[i]>current):current = day[i]
ans=max(ans, ans + current-ant-t)
print(ans)