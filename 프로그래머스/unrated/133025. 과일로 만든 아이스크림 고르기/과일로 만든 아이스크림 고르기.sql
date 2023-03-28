select fh.flavor
from 
    first_half as fh join icecream_info as icif
    on fh.flavor = icif.flavor
where
    total_order > 3000 and ingredient_type = 'fruit_based'
order by total_order desc