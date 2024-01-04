# Write your MySQL query statement below
with cte as (
    select
        session_id,
        duration/60 as mins
    from
        Sessions
)

select '[0-5>' as bin, count(session_id) as total from cte where mins < 5
union
select '[5-10>' as bin, count(session_id) as total from cte where mins >= 5 and mins < 10
union
select '[10-15>' as bin, count(session_id) as total from cte where mins >= 10 and mins < 15
union
select '15 or more' as bin, count(session_id) as total from cte where mins >= 15
