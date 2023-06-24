# Write your MySQL query statement below
select
    e.name
from
    Employee e
where
    4 < (select count(*) from Employee where managerId = e.id)