# Write your MySQL query statement below
with cte as (
    select
        c.name as customer_name,
        c.customer_id,
        o.order_id,
        o.order_date,
        rank() over(partition by o.customer_id order by order_date desc) as rk
    from
        Customers c
    join
        Orders o
    using (customer_id)
)

select
    customer_name,
    customer_id,
    order_id,
    order_date
from
    cte
where
    rk <= 3
order by
    customer_name asc, customer_id asc, order_date desc