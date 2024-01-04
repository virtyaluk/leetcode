# Write your MySQL query statement below
select
    seller_id
from
    Sales
group by
    seller_id
having
    sum(price) = (
        select
            sum(price)
        from
            Sales
        group by
            seller_id
        order by
            1 desc
        limit
            1
    )