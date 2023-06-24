# Write your MySQL query statement below
select
    student_id,
    course_id,
    grade
from
    (
        select
            *,
            rank()
        over(partition by student_id order by grade desc, course_id asc) as rn
        from Enrollments b
    ) a
where rn = 1
