import re

def get_url(page):
    res = re.search('<meta property="og:url" content="(.+)"/>', page)
    return res.group(1)

def get_word_count(word, page):
    word_len = len(word)
    page_len = len(page)
    cnt = 0
    for i in range(page_len):
        c = page[i]
        if i + word_len - 1 >= page_len:
            break
        chk = page[i: i + word_len]
        if chk == word:
            if i-1 >= 0 and i + word_len < page_len:
                if page[i-1].isalpha() == False and page[i + word_len].isalpha() == False:
                    cnt += 1
    return cnt
    
def find_external_link(page):
    ex_links = re.findall('<a href="(\S+)"', page)
    return ex_links
               
def solution(word, pages):
    n = len(pages)
    word = word.lower()
    
    url_idx = {} # url 별 index 
    idx_cnt = {} # idx 별 word count, 기본점수
    ex_cnt = {}  # idx 별 가리키는 외부링크 개수
    ex_idx = {} # idx 별 가리키는 외부링크 {{0: [1,2]}}
    idx_link_urls = []
    score = []
    for i in range(n):
        pages[i] = pages[i].lower()
        url_idx[get_url(pages[i])] = i 
        idx_cnt[i] = get_word_count(word, pages[i])
        ex_links = find_external_link(pages[i])
        ex_cnt[i] = len(ex_links)
        idx_link_urls.append(ex_links)
        score.append([idx_cnt[i], i])
    idx_income_link_idx = {}
    for i in range(n):
        ex_links = idx_link_urls[i]
        for ex_link in ex_links:
            if ex_link in url_idx:
                right = url_idx[ex_link]
                if right in idx_income_link_idx:
                    idx_income_link_idx[right].append(i)
                else:
                    idx_income_link_idx[right] = [i]
    for i in range(n):
        if i in idx_income_link_idx:
            ex_links = idx_income_link_idx[i]
            for idx in ex_links:
                score[i][0] += (idx_cnt[idx] / ex_cnt[idx])
    score = sorted(score)
    answer = score[n - 1][1]
    max_score = score[n - 1][0]
    if score[n - 2][0] == max_score:
        cnt = n - 2
        while cnt >= 0:
            if score[cnt][0] != max_score:
                break
            cnt -= 1
        answer = score[cnt + 1][1]     
    return answer