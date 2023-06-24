# Write your MySQL query statement below
with cte1 as (
    select
        *,
        rank() over(partition by exam_id order by score) as lowest_score,
        rank() over(partition by exam_id order by score desc) as highest_score
    from
        Exam
),
cte2 as (
    select
        distinct student_id
    from
        cte1
    where
        lowest_score = 1 or highest_score = 1
)

select
    distinct s.student_id,
    s.student_name
from
    Student s
join
    Exam e
on
    s.student_id = e.student_id
    and
    s.student_id not in (select student_id from cte2)
order by
    student_id asc