# # Write your MySQL query statement below
# # DATEDIFF ( datepart , startdate , enddate )

select
    e.employee_id
from
    Employees e
left join
    Logs l
using(employee_id)
group by
    e.employee_id
having max(needed_hours) * 60 > ifnull(sum(ceil(timestampdiff(second, in_time, out_time) / 60)), 0)