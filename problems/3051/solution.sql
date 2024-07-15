# Write your MySQL query statement below
select
    candidate_id
from
    Candidates
group by
    candidate_id
having
    sum(skill='Python' or skill = 'Tableau' or skill = 'PostgreSQL') = 3
order by
    candidate_id