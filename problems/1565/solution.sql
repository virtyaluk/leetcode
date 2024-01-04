# Write your MySQL query statement below
select
    left(order_date, 7) as month,
    count(distinct order_id) as order_count,
    count(distinct customer_id) as customer_count
from
    Orders
where
    invoice > 20
group by
    1
