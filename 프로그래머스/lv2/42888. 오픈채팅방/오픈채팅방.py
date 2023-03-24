def solution(record):
    answer = []
    map = {}
    for info in record:
        ids = info.split(' ')
        if ids[0] != 'Leave':
            map[ids[1]] = ids[2]
    for info in record:
        ids = info.split(' ')
        if ids[0] == 'Enter':
            answer.append(map[ids[1]] + '님이 들어왔습니다.')
        if ids[0] == 'Leave':
            answer.append(map[ids[1]] + '님이 나갔습니다.')
    return answer