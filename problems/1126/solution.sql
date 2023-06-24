# Write your MySQL query statement below
with cte1 as (
    select
        event_type,
        avg(occurences) as average
    from
        Events
    group by
        event_type
),
cte2 as (
    select
        e.business_id,
        count(*) as cnt
    from
        Events e
    join
        cte1 c
    on
        e.event_type = c.event_type
        and
        e.occurences > c.average
    group by
        business_id
)

select
    business_id
from
    cte2
where cnt > 1