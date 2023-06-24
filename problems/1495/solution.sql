# Write your MySQL query statement below
select
    distinct(c.title) as title
from
    Content c
join
    TVProgram t
on
    c.content_id = t.content_id
where
    c.content_type = 'MOVIES' and c.Kids_content = 'Y' and month(t.program_date) = 06 and year(t.program_date) = 2020