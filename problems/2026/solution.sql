# Write your MySQL query statement below
select
    problem_id
from
    Problems
where
    (likes / (likes + dislikes)) * 100 < 60.0
order by
    1 asc