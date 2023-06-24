# Write your MySQL query statement below
select
    product_id,
    new_price as price
from (
    select distinct product_id, 10 as new_price, '1970-08-14' as change_date from Products
    union
    select * from Products where change_date <= '2019-08-16' order by change_date desc
) t
group by 1