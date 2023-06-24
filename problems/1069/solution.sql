# Write your MySQL query statement below
select a.product_id, sum(quantity) as total_quantity
from Sales as a
left join Product as b on a.product_id = b.product_id
group by a.product_id
