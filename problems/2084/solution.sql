# Write your MySQL query statement below
select
    *
from
    Orders o
where
    not (
        o.order_type = 1
        and
        o.customer_id in (
            select
                distinct customer_id
            from
                Orders
            where
                order_type = 0
        )
    )