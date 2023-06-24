# Write your MySQL query statement below
with cte as (
    select
        distinct visited_on,
        sum(amount) over (order by visited_on range between interval 6 day preceding and current row) as amount,
        dense_rank() over (order by visited_on) as days
    from
        Customer
)

select
    visited_on,
    amount,
    round(amount / 7, 2) as average_amount
from
    cte
where
    days >= 7