select count(user_id)
from user_info
where age >= 20 and age <= 29 and YEAR(joined) = 2021 