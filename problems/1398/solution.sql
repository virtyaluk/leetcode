# Write your MySQL query statement below
select
    s.customer_id,
    c.customer_name
from (
    select
        customer_id,
        sum(case when product_name = 'A' then 1 else 0 end) as a,
        sum(case when product_name = 'B' then 1 else 0 end) as b,
        sum(case when product_name = 'C' then 1 else 0 end) as c
    from
        Orders
    group by
        customer_id
) s
left join
    Customers c
on
    c.customer_id = s.customer_id
where
    s.a > 0 and s.b > 0 and s.c = 0