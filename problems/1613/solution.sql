# Write your MySQL query statement below
with recursive nums as (
    select
        1 as value
    union all
    select
        value + 1
    from
        nums
    where
        nums.value < (select max(customer_id) from Customers)
)

select
    value as ids
from
    nums
where
    value not in (
        select
            customer_id
        from
            Customers
    )
order by
    ids asc