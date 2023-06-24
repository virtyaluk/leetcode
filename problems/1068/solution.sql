# Write your MySQL query statement below
select distinct a.product_name,
ifnull(year,0) as year,
ifnull(price, 0) as Price
from Product as a
join Sales as b on a.product_id = b.product_id