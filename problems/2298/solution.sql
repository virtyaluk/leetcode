# Write your MySQL query statement below
select
    sum(weekday(submit_date) >= 5) as weekend_cnt,
    sum(weekday(submit_date) < 5) as working_cnt
from
    Tasks