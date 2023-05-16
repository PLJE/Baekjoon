SELECT fp.product_id, fp.product_name, sum(fp.price * fo.amount) as total_sales
from food_order as fo join food_product as fp
on fo.product_id = fp.product_id
where fo.produce_date like '2022-05%'
group by fo.product_id
order by total_sales DESC, fo.product_id ASC
 