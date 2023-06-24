# Write your MySQL query statement below
with cte as (
    select
        order_id,
        avg(quantity) as avg_q,
        max(quantity) as m_q
    from
        OrdersDetails
    group by
        order_id
)

select
    order_id
from
    cte
where
    m_q > (select max(avg_q) from cte)