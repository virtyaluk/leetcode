# Write your MySQL query statement below
select
    round(avg(num * 1.0), 2) as median
from (
    select
        *,
        sum(frequency) over(order by num asc) as accumulated_sum,
        sum(frequency) over() / 2 as medium_num
    from
        Numbers
) as tmp
where
    accumulated_sum - frequency <= medium_num and accumulated_sum >= medium_num