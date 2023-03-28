select rest_id, rest_name, food_type, favorites, address, round(avg(review_score), 2) as score
from
(select rest.rest_id, rest.rest_name, rest.food_type, rest.favorites, rest.address, review.review_score
from 
    rest_info as rest join rest_review as review
    on rest.rest_id = review.rest_id
where rest.address LIKE '서울%') as combined
group by rest_id
order by score desc, favorites desc