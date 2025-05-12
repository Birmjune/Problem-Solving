# unsolved
# 팰린드롬 분할 시, 최소 개수

# 실패함... 다른 접근을 생각해보아야 할 듯. 첫 번째 idea는 dp. dp를 어떻게 관리하는지도 중요한 문제.

stridx = [-1 for i in range(2500)] # stridx[i]: s[i]를 마지막 원소로 하는 가장 긴 팰린드롬의 시작 인덱스
allsame = [0 for i in range(2500)] # 그 팰린드롬이 모든 값이 같은 경우면 1, 아니면 0
s = input()

for i in range(len(s)):
    if (i == 0):
        stridx[i] = 0
        allsame[i] = 1
    else:
        if (allsame[i-1] and s[i] == s[i-1]): # AA ... AA 팰린드롬 뒤에 A가 오는 경우, 그냥 추가
            stridx[i] = stridx[i-1]
            allsame[i] = 1
        else:
            if (stridx[i-1] > 0 and s[i] == s[stridx[i-1] - 1]): # X(팰린드롬)X인 경우, 뒤에 것 하나까지 해서 추가
                allsame[i] = 0
                stridx[i] = stridx[i-1] - 1
            else: # 그 이외의 경우는 
                allsame[i] = 1
                stridx[i] = i