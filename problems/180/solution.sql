# Write your MySQL query statement below
select
    distinct a.num as ConsecutiveNums
from
    Logs a
inner join
    Logs b
on
    a.num = b.num and a.id = b.id + 1
inner join
    Logs c
on
    b.num = c.num and b.id = c.id + 1