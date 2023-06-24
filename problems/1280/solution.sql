# Write your MySQL query statement below
select
    student_id,
    student_name,
    subject_name,
    (
        select
            count(*)
        from
          Examinations e
        where (e.student_id, e.subject_name) = (t.student_id, t.subject_name)
    ) as attended_exams
from
    (select
        student_id,
        student_name,
        subject_name
    from
        Students
    cross join
        Subjects) t
order by
    student_id, subject_name