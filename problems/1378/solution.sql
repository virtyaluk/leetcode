# Write your MySQL query statement below
select
a.unique_id,
b.name
from employeeuni a right join employees b using(id)