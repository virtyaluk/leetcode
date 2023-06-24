# Write your MySQL query statement below
select
    contest_id,
    round(100.0 / (select count(*) from Users) * count(*) , 2) as percentage
from
    Register
group by
    contest_id
order by
    percentage desc, contest_id