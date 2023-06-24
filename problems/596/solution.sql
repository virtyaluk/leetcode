# Write your MySQL query statement below
with cte as (
    select
        class,
        1 as num
    from
        Courses
)

select
    class
from
    cte
group by
    class
having
    sum(num) > 4