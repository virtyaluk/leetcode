# Write your MySQL query statement below
with cte1 as (
    select
        count(*) as cnt
    from
        NewYork
    where
        score >= 90
),
cte2 as (
    select
        count(*) as cnt
    from
        California
    where
        score >= 90
)

select
    case
        when a.cnt > b.cnt then 'New York University'
        when a.cnt < b.cnt then 'California University'
        else 'No Winner'
    end as winner
from
    cte1 a,
    cte2 b