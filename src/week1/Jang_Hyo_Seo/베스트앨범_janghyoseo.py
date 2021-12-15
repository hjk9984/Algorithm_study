def solution(genres, plays):
    answer = []
    # 주어진 곡의 갯수
    song_ea = len(genres)
    # genres, plays의 정보를 필요한 형태로 저장할 딕셔너리
    total_dic = {}
    # 곡의 갯수만큼 genres, plays의 각 인덱스에 접근하기
    for i in range(song_ea):
        # total_dic의 key에 장르가 없는 경우
        if genres[i] not in total_dic.keys():
            # 새로운 key를 생성하고 하위 딕셔너리 만들기
            # 하위 딕셔너리에 장르 별 총 재생수를 입력할 total key 생성 후 plays[i] 넣기
            # 곡 번호를 key로하고 plays[i] 넣기
            total_dic[genres[i]] = {'total': plays[i], i: plays[i]}
        # key가 존재하는 경우
        else:
            # total에 합 누적
            total_dic[genres[i]]['total'] += plays[i]
            # 곡 번호에 plays[i] 입력
            total_dic[genres[i]][i] = plays[i]
    # 만들어진 total_dic의 items으로 정렬하기
    # 각 genre의 하위 딕셔너리의 total key를 기준으로 내림차순 정렬
    sorted_genres_list = sorted(
        total_dic.items(), key=lambda x: x[1]['total'], reverse=True)
    # total을 기준으로 정렬한 리스트의 한 요소씩 접근
    for j in range(len(sorted_genres_list)):
        # 각 장르의 딕셔너리를 가져오기
        genre_dic = sorted_genres_list[j][1]
        # 가져온 각 장르의 딕셔너리에서 각 value를 기준으로 내림차순 정렬하기
        sorted_songs_list = sorted(
            genre_dic.items(), key=lambda x: x[1], reverse=True)
        # 두 개씩 answer 리스트에 넣기
        k = 1
        while k <= 2:
            answer.append(sorted_songs_list[k][0])
            # 리스트의 길이가 3미만인 경우 중단
            # total까지 포함되어 있는 리스트이므로 2일 때 total과 곡 1개의 play 수가 있으므로
            if (len(sorted_songs_list) < 3):
                break
            k += 1
    return answer