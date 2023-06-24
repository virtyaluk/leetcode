# Write your MySQL query statement below
select employee_id,team_size from employee join
(select team_id,count(*) as team_size from employee group by team_id  ) as t
 on employee.team_id = t.team_id