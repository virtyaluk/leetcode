# Write your MySQL query statement below
with cte as (
    select
        *,
        rank() over(partition by username order by endDate desc, startDate desc) as rk,
        count(*) over(partition by username) as cnt
    from
        UserActivity
)

select
    username,
    activity,
    startDate,
    endDate
from
    cte
where
    (cnt >= 2 and rk = 2)
    or
    (cnt = 1 and rk = 1)