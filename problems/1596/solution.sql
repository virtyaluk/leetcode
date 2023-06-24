# Write your MySQL query statement below
with cte as (
    select
        o.customer_id,
        o.product_id,
        p.product_name,
        count(*) as freq
    from
        Orders o
    join
        Products p
    using (product_id)
    group by
        o.customer_id, o.product_id
)

select
    customer_id,
    product_id,
    product_name
from
    cte
where
    (customer_id, freq) in (
        select
            customer_id,
            max(freq)
        from
            cte
        group by
            customer_id
    )