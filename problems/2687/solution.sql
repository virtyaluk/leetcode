# Write your MySQL query statement below
select
    bike_number,
    max(end_time) as end_time
from
    Bikes
group by
    1