# Write your MySQL query statement below
with cte as (
    select
        distinct sub_id as post_id
    from
        Submissions
    where
        parent_id is NULL
)

select
    a.post_id,
    count(distinct b.sub_id) as number_of_comments
from
    cte a
left join
    Submissions b
on
    a.post_id = b.parent_id
group by
    1
order by
    1