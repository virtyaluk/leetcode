# Write your MySQL query statement below
with cte as (
    select
        p.product_name,
        p.product_id,
        max(o.order_date) as order_date
    from
        Products p
    join
        Orders o
    using (product_id)
    group by
        1
        
)

select
    p.product_name,
    p.product_id,
    o.order_id,
    o.order_date
from
    Orders o
join
    cte p
on
    o.product_id = p.product_id and o.order_date = p.order_date
order by
    1 asc, 2 asc, 3 asc