# Write your MySQL query statement below
with tmp as (
    select
        log_id,
        (log_id - row_number() over(order by log_id)) as ind
    from
        Logs
)

select
    min(log_id) as start_id,
    max(log_id) as end_id
from
    tmp
group by
    ind
order by
    1 asc