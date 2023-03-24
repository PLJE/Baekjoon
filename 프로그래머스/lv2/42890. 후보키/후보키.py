import itertools

def solution(relations):
    answer = 0
    keys = []
    total_len = len(relations) # 총 row 개수
    column_len = len(relations[0]) # 4
    
    for i in range(1, column_len+1):
        combs = list(itertools.combinations(range(0, column_len), i))
        for comb in combs: # comb = (0,1) , (0,2) ...
            chk = []
            for row in relations:
                tp = []
                for c in comb:
                    tp.append(row[c])
                if tp not in chk:
                    chk.append(tp)
            cur_key = list(comb)
            if len(chk) == total_len:
                is_key = True
                for key in keys:
                    cnt = 0;
                    for idx in key:
                        if idx in cur_key:
                            cnt +=1
                    if cnt == len(key):
                        is_key = False
                if is_key:
                    answer += 1
                    keys.append(cur_key)
    return answer